// Copyright (c) 2000-2016 Synology Inc. All rights reserved.
#ifndef __SYNO_SHARE_KEYMANAGER_H__
#define __SYNO_SHARE_KEYMANAGER_H__

#include <iostream>
#include <list>
#include <map>
#include <json/json.h>

typedef struct __tag__MachineKey *MachineKey;
class CfgParserV1;
class Key;

enum KeyCypher {
	KEY_CYPHER_PASSPHRASE = 0,
	KEY_CYPHER_MACHINEKEY,
};

class KeyStore {
public:
	/**
	 * @brief Load store from @p location (e.g. "/volumeUSB1/usbshare"),
	 *        the returned store should be `delete` by caller. Assume this
	 *        machine if @p machine_uuid is not given.
	 */
	static KeyStore *load_instance(const std::string &location);
	static KeyStore *load_instance(
			const std::string &location, const std::string &machine_uuid);

	bool verify_passphrase(const std::string &passphrase) const;
	bool write_cfg() const;

	/**
	 * @brief Invoke @p visit for each key in this store.
	 */
	template <typename T> void for_each_key(T &visit)
	{
		for (std::list<Key>::iterator
				it = _keys.begin(); it != _keys.end(); ++it) {
			visit(*it);
		}
	}
	/**
	 * @brief Check whether @p share_uuid in this store or not.
	 */
	bool has_key(const std::string &share_uuid) const;
	/**
	 * @brief Find key by @p share_uuid then RETURN A COPY, the returned key
	 *        should be `delete` by caller. Return NULL if not found.
	 */
	Key *find_key(const std::string &share_uuid) const;
	/**
	 * @brief Copy @p key to this store, existing key (i.e. the same share uuid)
	 *        will be replaced. This does NOT check path of underlying secret
	 *        file, given @p key MUST NOT from other store.
	 */
	void set_key(const Key *key);
	/**
	 * @brief Destory key with given @p share_uuid, the underlying secret file
	 *        is also removed.
	 */
	bool destroy_key(const std::string &share_uuid);

	/**
	 * @brief Return location of this store, e.g. "/volumeUSB1/usbshare".
	 */
	std::string get_location() const;
	/**
	 * @brief Return path of secret files in this store, e.g.
	 *        "/volumeUSB1/usbshare/@keystore/$machine_uuid.store".
	 */
	std::string get_path() const;
	bool get_eject_after_boot() const;
	void set_eject_after_boot(bool eject_after_boot);
	bool change_passphrase(const std::string &old_passphrase, const std::string &new_passphrase);

	friend class CfgParserV1;

private:
	KeyStore(const std::string &location, const std::string &machine_uuid);

	std::string _location;
	std::string _machine_uuid;
	std::string _digest;
	bool _eject_after_boot;
	std::list<Key> _keys;
};  // class KeyStore

class Key {
public:
	/**
	 * @brief Create key, and underlying secret file, in @p dst_store with given
	 *        @p share_uuid and @p share_password. The secret file is encrypted
	 *        by @p passphrase or @p machine_key.
	 */
	static bool create_instance(
			const std::string &share_uuid, const std::string &share_password,
			const std::string &passphrase, KeyStore *dst_store);
	static bool create_instance(
			const std::string &share_uuid, const std::string &share_password,
			const MachineKey machine_key, KeyStore *dst_store);

	/**
	 * @brief Decrypt underlying secret file by @p passphrase or @p machine_key
	 *        then save result share password in @p share_password.
	 */
	bool decrypt(const std::string &passphrase, std::string &share_password) const;
	bool decrypt(const MachineKey machine_key, std::string &share_password) const;

	/**
	 * @brief Clone this key, with underlying secret file re-encrypted by
	 *        @p new_passphrase or @p new_machine_key, to @p dst_store.
	 */
	bool clone_to_store(
			const std::string &old_passphrase, const std::string &new_passphrase,
			KeyStore *dst_store) const;
	bool clone_to_store(
			const MachineKey old_machine_key, const MachineKey new_machine_key,
			KeyStore *dst_store) const;

	std::string get_share_uuid() const;
	KeyCypher get_cypher_type() const;
	bool get_mount_on_boot() const;
	void set_mount_on_boot(bool mount_on_boot);
	void set_description(const std::string &description);
	bool change_passphrase(const std::string &old_passphrase, const std::string &new_passphrase);

	/**
	 * @brief Convert this key to Json object, for example,
	 * {
	 *     "encrypt_type": 0 (i.e. by passphrase) | 1 (i.e. by machine key),
	 *     "description": "blah blah blah",
	 *     "auto_mount": false
	 * }
	 */
	Json::Value to_json_cfg() const;

	friend class CfgParserV1;

private:
	Key(const std::string &share_uuid, const std::string &store_path,
			KeyCypher cypher=KEY_CYPHER_PASSPHRASE);

	std::string _share_uuid;
	std::string _file_path;
	std::string _description;
	KeyCypher _cypher;
	bool _mount_on_boot;
};  // class Key

/**
 * @brief Get current machine uuid, create one if not exists.
 *
 * @return Result machine uuid or empty on error.
 */
std::string SYNOShareMachineUuidGet();

/**
 * @brief Initialize key store under @p location with given @p passphrase,
 *        result key store is @p location/@keystore/$machine_uuid.{cfg,store}.
 *        Error if target key store already exists.
 *
 * @param[in] passphrase    Plaintext passphrase for new key store.
 * @param[in] location      Key store location, e.g. "/volumeUSB1/usbshare".
 * @param[in] machine_uuid  Machine uuid, default for this machine.
 *
 * @return 0 on success, -1 on error.
 */
int SYNOShareKeyStoreInit(const std::string &passphrase, const std::string &location);
int SYNOShareKeyStoreInit(const std::string &passphrase,
		const std::string &location, const std::string &machine_uuid);

/**
 * @brief Enumerate locations which contain key store for this machine.
 *
 * @param[out] locations  Location list, e.g. ["/volumeUSB1/usbshare"].
 *
 * @return 0 on success, -1 on error.
 */
int SYNOShareKeyStoreSearch(std::list<std::string> &locations);

/**
 * @brief Build map to map share uuid to encryption share names.
 *
 * @paramp[out] uuid_map  Result map, share uuid to encryption share name.
 *
 * @return 0 on success, -1 on error.
 */
int SYNOShareEncShareUuidMapBuild(std::map<std::string, std::string> &uuid_map);

/**
 * @brief Get machine key, create one if not exists, the returned machine key
 *        should be `free` by caller.
 *
 * @param[in] with_secret_key  Whether get secret key which can be used to
 *                             decrypt share password later, default `false`.
 *
 * @return Machine key or NULL on error.
 */
MachineKey SYNOShareMachineKeyGet(bool with_secret_key=false);

/**
 * @brief Get base64-encoded public machine key.
 *
 * @return Result base64-encoded public machine key or empty on error.
 */
std::string SYNOShareBase64PublicMachineKeyGet();

/**
 * @brief Decode @p base64_pubkey as machine key which can be used to encrypt
 *        share password later. The returned machine key CAN NOT be used to
 *        decrypt share password and should be `free` by caller.
 *
 * @param[in] base64_pubkey  Base64-encoded public machine key.
 *
 * @return Result machine key or NULL on error.
 */
MachineKey SYNOSharePublicMachineKeyConvert(const std::string &base64_pubkey);

int SYNOShareAutoMountKeyList(std::map<std::string, std::string> &share_list);
int SYNOShareAutoMountKeyMigrate(std::map<std::string, std::string> &share_list, bool blOverwrite);

#endif  // __SYNO_SHARE_KEYMANAGER_H__
// vim:ts=4 sts=4 sw=4
