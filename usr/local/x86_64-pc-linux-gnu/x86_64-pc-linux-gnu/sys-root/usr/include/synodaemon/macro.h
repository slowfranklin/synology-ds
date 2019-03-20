/* Copyright (c) 2000-2016 Synology Inc. All rights reserved. */
#ifndef _SYNO_DAEMON_MACRO_H_
#define _SYNO_DAEMON_MACRO_H_

#include <memory>

// For setter and getter
#define SYNODAEMON_GETTER_REF(name, funcName, type) \
	const type & Get##funcName##Ref () const { return name##_; }

#define SYNODAEMON_GETTER_VAL(name, funcName, type) \
	type Get##funcName () const { return name##_; }

#define SYNODAEMON_SETTER_REF(name, funcName, type, className) \
	className & Set##funcName (const type &val) { name##_ = val; return *this; } \
	className & Set##funcName (type &&val) { name##_ = val; return *this; }

#define SYNODAEMON_SETTER_VAL(name, funcName, type, className) \
	className & Set##funcName (type val) { name##_ = val; return *this; } \

#define SYNODAEMON_GETSET_REF(name, funcName, type, className) \
	SYNODAEMON_GETTER_REF(name, funcName, type) \
	SYNODAEMON_SETTER_REF(name, funcName, type, className)

#define SYNODAEMON_GETSET_VAL(name, funcName, type, className) \
	SYNODAEMON_GETTER_VAL(name, funcName, type) \
	SYNODAEMON_SETTER_VAL(name, funcName, type, className)

//default cstor mstor
#define SYNODAEMON_DEFAULT_COPY_CTOR(className) \
	className(const className &) = default; \
	className& operator=(const className &) = default

#define SYNODAEMON_DEFAULT_MOVE_CTOR(className) \
	className(className &&) = default; \
	className& operator=(className &&) = default;

#define SYNODAEMON_DEFAULT_CTOR_DTOR(className) \
	className() = default; \
	SYNODAEMON_DEFAULT_COPY_CTOR(className); \
	SYNODAEMON_DEFAULT_MOVE_CTOR(className); \
	virtual ~className() = default;

//no copyable interface
#define SYNODAEMON_NOCOPYABLE_CLASS(Type) \
	Type& operator=(Type&) = delete; \
	Type& operator=(const Type&) = delete; \
	Type(Type&) = delete; \
	Type(const Type&) = delete;

//shared ptr
#define SYNODAEMON_DECLARE_SHARED_PTR(Type) \
	SYNODAEMON_DECLARE_SHARED_PTR_EX(Type, Type)

#define SYNODAEMON_DECLARE_SHARED_PTR_EX(Type, Name) \
	class Type; \
	typedef std::shared_ptr<Type> Name##Ptr; \
	typedef std::weak_ptr<Type> Name##WeakPtr;

namespace synodaemon {

template <typename Type, typename ...Args>
std::shared_ptr<Type> newClass(Args&& ...args) {
	return std::make_shared<Type>(std::forward<Args>(args)...);
}

} //end of synodaemon

#endif
