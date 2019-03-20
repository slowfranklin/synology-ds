#ifndef __SYNO_UTILS_H__
#define __SYNO_UTILS_H__

#include <string>
#include <vector>

namespace SYNOUtils {

struct ProcessRunnerPriv;
class ProcessRunner {
public:
	ProcessRunner(const char* szProgPath, const char* argv0, 
				  const char* argv1=NULL, const char* argv2=NULL,
				  const char* argv3=NULL, const char* argv4=NULL,
				  const char* argv5=NULL, const char* argv6=NULL,
				  const char* argv7=NULL, const char* argv8=NULL);
	ProcessRunner(const char* szProgPath, const char** argv);
	ProcessRunner(const ProcessRunner& proc);
	~ProcessRunner();
	ProcessRunner& operator=(const ProcessRunner& proc);

	int run(bool fWaitPid = true, bool captureOutput = false);
	int run(bool bWaitPid, bool bCaptureStdout, bool bCaptureStderr);
	int run(int flag, bool bCaptureStdout, bool bCaptureStderr);
	int run(int flag, bool bCaptureStdout, bool bCaptureStderr, const int fdOut);

	std::string toString();
	void addArguments(const char* argv0, 
				  const char* argv1=NULL, const char* argv2=NULL,
				  const char* argv3=NULL, const char* argv4=NULL,
				  const char* argv5=NULL, const char* argv6=NULL,
				  const char* argv7=NULL, const char* argv8=NULL);
	void addEnv(const std::string& strName, const std::string& strValue);

	std::string getCapturedOutput();
	std::string getCapturedOutputErr();

	void setRuntimeIdentity(const std::string &username, const bool permanent);

private:
	ProcessRunnerPriv* d;
};

struct ConfParserPriv;

/**
 * @short CConfParser is used to parse and create configuration file.
 *
 * The format of configuration is similar to the format of Windows
 * .ini file. The config file is divided into multiple sections and
 * each section contains mutiple key-value entries. For example:
 * <pre>
 * [section_name]
 * # comment
 * key1="value1" # comment
 * key2="value2"
 * </pre>
 * 
 * To use this class:
 * <pre>
 *  ConfParser parser("win.ini");
 *  ConfParser parser;
 * </pre>
 * After the file is parsed, you can use various methods to
 * access section values.
 */ 
class ConfParser {
public:
	typedef std::vector<std::string> StringVector;

	/**
	 * Constructor.
	 * @param strFilePath Configuration file path.
	 */ 
	ConfParser(const char* strFilePath);

	/**
     * Contructor
     * @param Contruct an empty configuration data.
	 */
	ConfParser();

	bool loadFromFile(const char* strFilePath);
	/**
	 * Enumeration all section names.
	 */ 
	StringVector enumSections();

	/** 
	 * Query whether strSecName exists.
	 * @return return if strSecName exists.
	 */ 
	bool hasSection(const std::string& strSecName);

	/**
	 * Enumerate all keys in section strSecName.
	 */ 
	StringVector enumSectionKeys(const std::string& strSecName);

	/**
	 * Create  a new section in configuration file.
	 * @return return false if the section already exists.
	 */ 
	bool createSection(const std::string& strSecName);
	/**
	 * Empty the entries in the section, this section still exists but with empty entries.
	 */
	void emptySection(const std::string& strSecName);
	
	/**
	 * remove strSecName toally
	 */
	void removeSection(const std::string& strSecName);

	/**
	 * Get string value from the assigned section and key.
	 * @return false if the assigned section or key does not exist.
	 */ 
	bool getValue(const std::string& strSecName, const std::string& strKey, std::string& strVal);

	std::string getString(const std::string& strSecName, const std::string& strKey, const std::string& strDefault);
	int getInt(const std::string& strSecName, const std::string& strKey, int defval);
    bool getOptions(const std::string& strSecName, const std::string& strKey, 
                    const std::string& strDelimit, StringVector& strOpts);
	/**
	 * Set string vaule in strSection with key=strKey.
	 * If createEntry is true, a new section/entry will be created
	 * for unexsited string entry.
	 */ 
	void setValue(const std::string& strSecName, const std::string& strKey,
				  const std::string& strVal, bool createEntry=true);

	void setValue(const std::string& strSecName, const std::string& strKey,
				  int val, bool createEntry=true);

	/** 
	 * Save data to strFilePath.
	 * If strFilePath is std::string::null, use the original fileName.
	 * @return return true if the operation is successfully.
	 */ 
	bool saveFile(const char* strFilePath);
	bool saveFile(FILE* fptr);
	virtual ~ConfParser();
private:
	
	ConfParserPriv* d;
	bool loadFile(const char* filePath, StringVector& lines);

	std::string matchSection(const std::string strSect);
	bool matchKeyValue(const std::string strData, std::string& key, std::string& val);
	
};

std::string GetPathDirName(const std::string& strPath);
std::string GetPathBaseName(const std::string& strPath);
std::string GetPathExt(const std::string& strPath);

bool StringExplode(std::vector<std::string> &strings, const std::string &strSource, const char *szFind);
}
#endif //__SYNO_UTILS_H__
