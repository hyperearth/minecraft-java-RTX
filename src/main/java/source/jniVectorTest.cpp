// Generated by JavaCPP version 1.5.3: DO NOT EDIT THIS FILE


#ifdef _WIN32
    #define _JAVASOFT_JNI_MD_H_

    #define JNIEXPORT __declspec(dllexport)
    #define JNIIMPORT __declspec(dllimport)
    #define JNICALL __stdcall

    typedef int jint;
    typedef long long jlong;
    typedef signed char jbyte;
#elif defined(__GNUC__) && !defined(__ANDROID__)
    #define _JAVASOFT_JNI_MD_H_

    #define JNIEXPORT __attribute__((visibility("default")))
    #define JNIIMPORT
    #define JNICALL

    typedef int jint;
    typedef long long jlong;
    typedef signed char jbyte;
#endif

#include <jni.h>

#ifdef __ANDROID__
    #include <android/log.h>
#elif defined(__APPLE__) && defined(__OBJC__)
    #include <TargetConditionals.h>
    #include <Foundation/Foundation.h>
#endif

#ifdef __linux__
    #include <malloc.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <sys/sysinfo.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <dlfcn.h>
    #include <link.h>
    #include <pthread.h>
#elif defined(__APPLE__)
    #include <sys/types.h>
    #include <sys/sysctl.h>
    #include <mach/mach_init.h>
    #include <mach/mach_host.h>
    #include <mach/task.h>
    #include <unistd.h>
    #include <dlfcn.h>
    #include <mach-o/dyld.h>
    #include <pthread.h>
#elif defined(_WIN32) && !defined(NO_WINDOWS_H)
    #define NOMINMAX
    #include <windows.h>
    #include <psapi.h>
#endif

#if defined(__ANDROID__) || TARGET_OS_IPHONE
    #define NewWeakGlobalRef(obj) NewGlobalRef(obj)
    #define DeleteWeakGlobalRef(obj) DeleteGlobalRef(obj)
#endif

#include <limits.h>
#include <stddef.h>
#ifndef _WIN32
    #include <stdint.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <exception>
#include <memory>
#include <new>

#define jlong_to_ptr(a) ((void*)(uintptr_t)(a))
#define ptr_to_jlong(a) ((jlong)(uintptr_t)(a))

#if defined(_MSC_VER)
    #define JavaCPP_noinline __declspec(noinline)
    #define JavaCPP_hidden /* hidden by default */
#elif defined(__GNUC__)
    #define JavaCPP_noinline __attribute__((noinline)) __attribute__ ((unused))
    #define JavaCPP_hidden   __attribute__((visibility("hidden"))) __attribute__ ((unused))
#else
    #define JavaCPP_noinline
    #define JavaCPP_hidden
#endif
#if __cplusplus >= 201103L || _MSC_VER >= 1900
    #define JavaCPP_override override
#else
    #define JavaCPP_override
#endif

#include <vector>

static JavaVM* JavaCPP_vm = NULL;
static bool JavaCPP_haveAllocObject = false;
static bool JavaCPP_haveNonvirtual = false;
static const char* JavaCPP_classNames[10] = {
        "org/bytedeco/javacpp/Pointer",
        "java/lang/String",
        "org/bytedeco/javacpp/Pointer$NativeDeallocator",
        "org/bytedeco/javacpp/Loader",
        "java/nio/Buffer",
        "java/lang/Object",
        "java/lang/NullPointerException",
        "org/bytedeco/javacpp/PointerPointer",
        "java/lang/RuntimeException",
        "net/fabricmc/minevkr/jivix/VectorTest$PointerVectorVector" };
static jclass JavaCPP_classes[10] = { NULL };
static jfieldID JavaCPP_addressFID = NULL;
static jfieldID JavaCPP_positionFID = NULL;
static jfieldID JavaCPP_limitFID = NULL;
static jfieldID JavaCPP_capacityFID = NULL;
static jfieldID JavaCPP_deallocatorFID = NULL;
static jfieldID JavaCPP_ownerAddressFID = NULL;
static jmethodID JavaCPP_initMID = NULL;
static jmethodID JavaCPP_arrayMID = NULL;
static jmethodID JavaCPP_arrayOffsetMID = NULL;
static jfieldID JavaCPP_bufferPositionFID = NULL;
static jfieldID JavaCPP_bufferLimitFID = NULL;
static jfieldID JavaCPP_bufferCapacityFID = NULL;
static jmethodID JavaCPP_stringMID = NULL;
static jmethodID JavaCPP_getBytesMID = NULL;
static jmethodID JavaCPP_toStringMID = NULL;

static inline void JavaCPP_log(const char* fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
#ifdef __ANDROID__
    __android_log_vprint(ANDROID_LOG_ERROR, "javacpp", fmt, ap);
#elif defined(__APPLE__) && defined(__OBJC__)
    NSLogv([NSString stringWithUTF8String:fmt], ap);
#else
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, "\n");
#endif
    va_end(ap);
}

#ifdef __ANDROID__
    static pthread_key_t JavaCPP_current_env;
    static JavaCPP_noinline void JavaCPP_detach_env(void *data)
    {
        if (JavaCPP_vm) {
            JavaCPP_vm->DetachCurrentThread();
        }
    }
    static JavaCPP_noinline void JavaCPP_create_pthread_key(void)
    {
        pthread_key_create(&JavaCPP_current_env, JavaCPP_detach_env);
    }
#endif

static JavaCPP_noinline jclass JavaCPP_getClass(JNIEnv* env, int i) {
    if (JavaCPP_classes[i] == NULL && env->PushLocalFrame(1) == 0) {
        jclass cls = env->FindClass(JavaCPP_classNames[i]);
        if (cls == NULL || env->ExceptionCheck()) {
            JavaCPP_log("Error loading class %s.", JavaCPP_classNames[i]);
            return NULL;
        }
        JavaCPP_classes[i] = (jclass)env->NewWeakGlobalRef(cls);
        if (JavaCPP_classes[i] == NULL || env->ExceptionCheck()) {
            JavaCPP_log("Error creating global reference of class %s.", JavaCPP_classNames[i]);
            return NULL;
        }
        env->PopLocalFrame(NULL);
    }
    return JavaCPP_classes[i];
}

static JavaCPP_noinline jfieldID JavaCPP_getFieldID(JNIEnv* env, int i, const char* name, const char* sig) {
    jclass cls = JavaCPP_getClass(env, i);
    if (cls == NULL) {
        return NULL;
    }
    jfieldID fid = env->GetFieldID(cls, name, sig);
    if (fid == NULL || env->ExceptionCheck()) {
        JavaCPP_log("Error getting field ID of %s/%s", JavaCPP_classNames[i], name);
        return NULL;
    }
    return fid;
}

static JavaCPP_noinline jmethodID JavaCPP_getMethodID(JNIEnv* env, int i, const char* name, const char* sig) {
    jclass cls = JavaCPP_getClass(env, i);
    if (cls == NULL) {
        return NULL;
    }
    jmethodID mid = env->GetMethodID(cls, name, sig);
    if (mid == NULL || env->ExceptionCheck()) {
        JavaCPP_log("Error getting method ID of %s/%s", JavaCPP_classNames[i], name);
        return NULL;
    }
    return mid;
}

static JavaCPP_noinline jmethodID JavaCPP_getStaticMethodID(JNIEnv* env, int i, const char* name, const char* sig) {
    jclass cls = JavaCPP_getClass(env, i);
    if (cls == NULL) {
        return NULL;
    }
    jmethodID mid = env->GetStaticMethodID(cls, name, sig);
    if (mid == NULL || env->ExceptionCheck()) {
        JavaCPP_log("Error getting static method ID of %s/%s", JavaCPP_classNames[i], name);
        return NULL;
    }
    return mid;
}

static JavaCPP_noinline jobject JavaCPP_createPointer(JNIEnv* env, int i, jclass cls = NULL) {
    if (cls == NULL && (cls = JavaCPP_getClass(env, i)) == NULL) {
        return NULL;
    }
    if (JavaCPP_haveAllocObject) {
        return env->AllocObject(cls);
    } else {
        jmethodID mid = env->GetMethodID(cls, "<init>", "(Lorg/bytedeco/javacpp/Pointer;)V");
        if (mid == NULL || env->ExceptionCheck()) {
            JavaCPP_log("Error getting Pointer constructor of %s, while VM does not support AllocObject()", JavaCPP_classNames[i]);
            return NULL;
        }
        return env->NewObject(cls, mid, NULL);
    }
}

static JavaCPP_noinline void JavaCPP_initPointer(JNIEnv* env, jobject obj, const void* ptr, jlong size, void* owner, void (*deallocator)(void*)) {
    if (owner != NULL && deallocator != NULL) {
        jvalue args[4];
        args[0].j = ptr_to_jlong(ptr);
        args[1].j = size;
        args[2].j = ptr_to_jlong(owner);
        args[3].j = ptr_to_jlong(deallocator);
        if (JavaCPP_haveNonvirtual) {
            env->CallNonvirtualVoidMethodA(obj, JavaCPP_getClass(env, 0), JavaCPP_initMID, args);
        } else {
            env->CallVoidMethodA(obj, JavaCPP_initMID, args);
        }
    } else {
        env->SetLongField(obj, JavaCPP_addressFID, ptr_to_jlong(ptr));
        env->SetLongField(obj, JavaCPP_limitFID, (jlong)size);
        env->SetLongField(obj, JavaCPP_capacityFID, (jlong)size);
    }
}

static JavaCPP_noinline jstring JavaCPP_createString(JNIEnv* env, const char* ptr) {
    if (ptr == NULL) {
        return NULL;
    }
#ifdef MODIFIED_UTF8_STRING
    return env->NewStringUTF(ptr);
#else
    size_t length = strlen(ptr);
    jbyteArray bytes = env->NewByteArray(length < INT_MAX ? length : INT_MAX);
    env->SetByteArrayRegion(bytes, 0, length < INT_MAX ? length : INT_MAX, (signed char*)ptr);
    return (jstring)env->NewObject(JavaCPP_getClass(env, 1), JavaCPP_stringMID, bytes);
#endif
}

class JavaCPP_hidden JavaCPP_exception : public std::exception {
public:
    JavaCPP_exception(const char* str) throw() {
        if (str == NULL) {
            strcpy(msg, "Unknown exception.");
        } else {
            strncpy(msg, str, sizeof(msg));
            msg[sizeof(msg) - 1] = 0;
        }
    }
    virtual const char* what() const throw() { return msg; }
    char msg[1024];
};

#ifndef GENERIC_EXCEPTION_CLASS
#define GENERIC_EXCEPTION_CLASS std::exception
#endif
#ifndef GENERIC_EXCEPTION_TOSTRING
#define GENERIC_EXCEPTION_TOSTRING what()
#endif
static JavaCPP_noinline jthrowable JavaCPP_handleException(JNIEnv* env, int i) {
    jstring str = NULL;
    try {
        throw;
    } catch (GENERIC_EXCEPTION_CLASS& e) {
        str = JavaCPP_createString(env, e.GENERIC_EXCEPTION_TOSTRING);
    } catch (...) {
        str = JavaCPP_createString(env, "Unknown exception.");
    }
    jmethodID mid = JavaCPP_getMethodID(env, i, "<init>", "(Ljava/lang/String;)V");
    if (mid == NULL) {
        return NULL;
    }
    return (jthrowable)env->NewObject(JavaCPP_getClass(env, i), mid, str);
}

static JavaCPP_noinline void* JavaCPP_getPointerOwner(JNIEnv* env, jobject obj) {
    if (obj != NULL) {
        jobject deallocator = env->GetObjectField(obj, JavaCPP_deallocatorFID);
        if (deallocator != NULL && env->IsInstanceOf(deallocator, JavaCPP_getClass(env, 2))) {
            return jlong_to_ptr(env->GetLongField(deallocator, JavaCPP_ownerAddressFID));
        }
    }
    return NULL;
}

#include <vector>
template<typename P, typename T = P, typename A = std::allocator<T> > class JavaCPP_hidden VectorAdapter {
public:
    VectorAdapter(const P* ptr, typename std::vector<T,A>::size_type size, void* owner) : ptr((P*)ptr), size(size), owner(owner),
        vec2(ptr ? std::vector<T,A>((P*)ptr, (P*)ptr + size) : std::vector<T,A>()), vec(vec2) { }
    VectorAdapter(const std::vector<T,A>& vec) : ptr(0), size(0), owner(0), vec2(vec), vec(vec2) { }
    VectorAdapter(      std::vector<T,A>& vec) : ptr(0), size(0), owner(0), vec(vec) { }
    VectorAdapter(const std::vector<T,A>* vec) : ptr(0), size(0), owner(0), vec(*(std::vector<T,A>*)vec) { }
    void assign(P* ptr, typename std::vector<T,A>::size_type size, void* owner) {
        this->ptr = ptr;
        this->size = size;
        this->owner = owner;
        vec.assign(ptr, ptr + size);
    }
    static void deallocate(void* owner) { operator delete(owner); }
    operator P*() {
        if (vec.size() > size) {
            ptr = (P*)(operator new(sizeof(P) * vec.size(), std::nothrow_t()));
        }
        if (ptr) {
            std::copy(vec.begin(), vec.end(), ptr);
        }
        size = vec.size();
        owner = ptr;
        return ptr;
    }
    operator const P*()        { size = vec.size(); return &vec[0]; }
    operator std::vector<T,A>&() { return vec; }
    operator std::vector<T,A>*() { return ptr ? &vec : 0; }
    P* ptr;
    typename std::vector<T,A>::size_type size;
    void* owner;
    std::vector<T,A> vec2;
    std::vector<T,A>& vec;
};

#include <string>
template<typename T = char> class JavaCPP_hidden StringAdapter {
public:
    StringAdapter(const          char* ptr, typename std::basic_string<T>::size_type size, void* owner) : ptr((T*)ptr), size(size), owner(owner),
        str2(ptr ? (T*)ptr : "", ptr ? (size > 0 ? size : strlen((char*)ptr)) : 0), str(str2) { }
    StringAdapter(const signed   char* ptr, typename std::basic_string<T>::size_type size, void* owner) : ptr((T*)ptr), size(size), owner(owner),
        str2(ptr ? (T*)ptr : "", ptr ? (size > 0 ? size : strlen((char*)ptr)) : 0), str(str2) { }
    StringAdapter(const unsigned char* ptr, typename std::basic_string<T>::size_type size, void* owner) : ptr((T*)ptr), size(size), owner(owner),
        str2(ptr ? (T*)ptr : "", ptr ? (size > 0 ? size : strlen((char*)ptr)) : 0), str(str2) { }
    StringAdapter(const       wchar_t* ptr, typename std::basic_string<T>::size_type size, void* owner) : ptr((T*)ptr), size(size), owner(owner),
        str2(ptr ? (T*)ptr : L"", ptr ? (size > 0 ? size : wcslen((wchar_t*)ptr)) : 0), str(str2) { }
    StringAdapter(const unsigned short* ptr, typename std::basic_string<T>::size_type size, void* owner) : ptr((T*)ptr), size(size), owner(owner),
        str2(ptr ? (T*)ptr : L"", ptr ? (size > 0 ? size : wcslen((wchar_t*)ptr)) : 0), str(str2) { }
    StringAdapter(const   signed   int* ptr, typename std::basic_string<T>::size_type size, void* owner) : ptr((T*)ptr), size(size), owner(owner),
        str2(ptr ? (T*)ptr : L"", ptr ? (size > 0 ? size : wcslen((wchar_t*)ptr)) : 0), str(str2) { }
    StringAdapter(const std::basic_string<T>& str) : ptr(0), size(0), owner(0), str2(str), str(str2) { }
    StringAdapter(      std::basic_string<T>& str) : ptr(0), size(0), owner(0), str(str) { }
    StringAdapter(const std::basic_string<T>* str) : ptr(0), size(0), owner(0), str(*(std::basic_string<T>*)str) { }
    void assign(char* ptr, typename std::basic_string<T>::size_type size, void* owner) {
        this->ptr = ptr;
        this->size = size;
        this->owner = owner;
        str.assign(ptr ? ptr : "", ptr ? (size > 0 ? size : strlen((char*)ptr)) : 0);
    }
    void assign(const          char* ptr, typename std::basic_string<T>::size_type size, void* owner) { assign((char*)ptr, size, owner); }
    void assign(const signed   char* ptr, typename std::basic_string<T>::size_type size, void* owner) { assign((char*)ptr, size, owner); }
    void assign(const unsigned char* ptr, typename std::basic_string<T>::size_type size, void* owner) { assign((char*)ptr, size, owner); }
    void assign(wchar_t* ptr, typename std::basic_string<T>::size_type size, void* owner) {
        this->ptr = ptr;
        this->size = size;
        this->owner = owner;
        str.assign(ptr ? ptr : L"", ptr ? (size > 0 ? size : wcslen((wchar_t*)ptr)) : 0);
    }
    void assign(const        wchar_t* ptr, typename std::basic_string<T>::size_type size, void* owner) { assign((wchar_t*)ptr, size, owner); }
    void assign(const unsigned short* ptr, typename std::basic_string<T>::size_type size, void* owner) { assign((wchar_t*)ptr, size, owner); }
    void assign(const   signed   int* ptr, typename std::basic_string<T>::size_type size, void* owner) { assign((wchar_t*)ptr, size, owner); }
    static void deallocate(void* owner) { delete[] (T*)owner; }
    operator char*() {
        const char* data = str.data();
        if (str.size() > size) {
            ptr = new (std::nothrow) char[str.size()+1];
            if (ptr) memset(ptr, 0, str.size()+1);
        }
        if (ptr && memcmp(ptr, data, str.size()) != 0) {
            memcpy(ptr, data, str.size());
            if (size > str.size()) ptr[str.size()] = 0;
        }
        size = str.size();
        owner = ptr;
        return ptr;
    }
    operator       signed   char*() { return (signed   char*)(operator char*)(); }
    operator       unsigned char*() { return (unsigned char*)(operator char*)(); }
    operator const          char*() { size = str.size(); return                 str.c_str(); }
    operator const signed   char*() { size = str.size(); return (signed   char*)str.c_str(); }
    operator const unsigned char*() { size = str.size(); return (unsigned char*)str.c_str(); }
    operator wchar_t*() {
        const wchar_t* data = str.data();
        if (str.size() > size) {
            ptr = new (std::nothrow) wchar_t[str.size()+1];
            if (ptr) memset(ptr, 0, sizeof(wchar_t) * (str.size()+1));
        }
        if (ptr && memcmp(ptr, data, sizeof(wchar_t) * str.size()) != 0) {
            memcpy(ptr, data, sizeof(wchar_t) * str.size());
            if (size > str.size()) ptr[str.size()] = 0;
        }
        size = str.size();
        owner = ptr;
        return ptr;
    }
    operator     unsigned   short*() { return (unsigned short*)(operator wchar_t*)(); }
    operator       signed     int*() { return (  signed   int*)(operator wchar_t*)(); }
    operator const        wchar_t*() { size = str.size(); return                  str.c_str(); }
    operator const unsigned short*() { size = str.size(); return (unsigned short*)str.c_str(); }
    operator const   signed   int*() { size = str.size(); return (  signed   int*)str.c_str(); }
    operator         std::basic_string<T>&() { return str; }
    operator         std::basic_string<T>*() { return ptr ? &str : 0; }
    T* ptr;
    typename std::basic_string<T>::size_type size;
    void* owner;
    std::basic_string<T> str2;
    std::basic_string<T>& str;
};

#ifdef SHARED_PTR_NAMESPACE
template<class T> class SharedPtrAdapter {
public:
    typedef SHARED_PTR_NAMESPACE::shared_ptr<T> S;
    SharedPtrAdapter(const T* ptr, size_t size, void* owner) : ptr((T*)ptr), size(size), owner(owner),
            sharedPtr2(owner != NULL && owner != ptr ? *(S*)owner : S((T*)ptr)), sharedPtr(sharedPtr2) { }
    SharedPtrAdapter(const S& sharedPtr) : ptr(0), size(0), owner(0), sharedPtr2(sharedPtr), sharedPtr(sharedPtr2) { }
    SharedPtrAdapter(      S& sharedPtr) : ptr(0), size(0), owner(0), sharedPtr(sharedPtr) { }
    SharedPtrAdapter(const S* sharedPtr) : ptr(0), size(0), owner(0), sharedPtr(*(S*)sharedPtr) { }
    void assign(T* ptr, size_t size, void* owner) {
        this->ptr = ptr;
        this->size = size;
        this->owner = owner;
        this->sharedPtr = owner != NULL && owner != ptr ? *(S*)owner : S((T*)ptr);
    }
    static void deallocate(void* owner) { delete (S*)owner; }
    operator typename SHARED_PTR_NAMESPACE::remove_const<T>::type*() {
        ptr = sharedPtr.get();
        if (owner == NULL || owner == ptr) {
            owner = new S(sharedPtr);
        }
        return (typename SHARED_PTR_NAMESPACE::remove_const<T>::type*)ptr;
    }
    operator S&() { return sharedPtr; }
    operator S*() { return &sharedPtr; }
    T* ptr;
    size_t size;
    void* owner;
    S sharedPtr2;
    S& sharedPtr;
};
#endif

#ifdef UNIQUE_PTR_NAMESPACE
template<class T, class D = UNIQUE_PTR_NAMESPACE::default_delete<T> > class UniquePtrAdapter {
public:
    typedef UNIQUE_PTR_NAMESPACE::unique_ptr<T,D> U;
    UniquePtrAdapter(const T* ptr, size_t size, void* owner) : ptr((T*)ptr), size(size), owner(owner),
            uniquePtr2(owner != NULL && owner != ptr ? U() : U((T*)ptr)),
            uniquePtr(owner != NULL && owner != ptr ? *(U*)owner : uniquePtr2) { }
    UniquePtrAdapter(U&& uniquePtr) : ptr(0), size(0), owner(0), uniquePtr2(UNIQUE_PTR_NAMESPACE::move(uniquePtr)), uniquePtr(uniquePtr2) { }
    UniquePtrAdapter(const U& uniquePtr) : ptr(0), size(0), owner(0), uniquePtr((U&)uniquePtr) { }
    UniquePtrAdapter(      U& uniquePtr) : ptr(0), size(0), owner(0), uniquePtr(uniquePtr) { }
    UniquePtrAdapter(const U* uniquePtr) : ptr(0), size(0), owner(0), uniquePtr(*(U*)uniquePtr) { }
    void assign(T* ptr, size_t size, void* owner) {
        this->ptr = ptr;
        this->size = size;
        this->owner = owner;
        this->uniquePtr = owner != NULL && owner != ptr ? *(U*)owner : U((T*)ptr);
    }
    static void deallocate(void* owner) { delete (U*)owner; }
    operator typename UNIQUE_PTR_NAMESPACE::remove_const<T>::type*() {
        ptr = uniquePtr.get();
        if (ptr == uniquePtr2.get() && (owner == NULL || owner == ptr)) {
            // only move the pointer if we actually own it through uniquePtr2
            owner = new U(UNIQUE_PTR_NAMESPACE::move(uniquePtr));
        }
        return (typename UNIQUE_PTR_NAMESPACE::remove_const<T>::type*)ptr;
    }
    operator U&() const { return uniquePtr; }
    operator U&&() { return UNIQUE_PTR_NAMESPACE::move(uniquePtr); }
    operator U*() { return &uniquePtr; }
    T* ptr;
    size_t size;
    void* owner;
    U uniquePtr2;
    U& uniquePtr;
};
#endif

#if __cplusplus >= 201103L || _MSC_VER >= 1900
#include <utility>
template<class T> class MoveAdapter {
public:
    MoveAdapter(const T* ptr, size_t size, void* owner) : ptr(&movedPtr), size(size), owner(owner), movedPtr(std::move(*(T*)ptr)) { }
    MoveAdapter(const T& ptr) : ptr(&movedPtr), size(0), owner(0), movedPtr(std::move((T&)ptr)) { }
    MoveAdapter(T&& ptr) : ptr(&movedPtr), size(0), owner(0), movedPtr((T&&)ptr) { }
    void assign(T* ptr, size_t size, void* owner) {
        this->ptr = &this->movedPtr;
        this->size = size;
        this->owner = owner;
        this->movedPtr = std::move(*ptr);
    }
    static void deallocate(void* owner) { delete (T*)owner; }
    operator T*() {
        ptr = new T(std::move(movedPtr));
        owner = ptr;
        return ptr;
    }
    operator const T*() { return ptr; }
    operator T&&() { return std::move(movedPtr); }
    T* ptr;
    size_t size;
    void* owner;
    T movedPtr;
};
#endif




static void JavaCPP_net_fabricmc_minevkr_jivix_VectorTest_00024PointerVectorVector_deallocate(void *p) { delete (::std::vector<std::vector<void*> >*)p; }

static const char* JavaCPP_members[10][2] = {
        { NULL },
        { NULL },
        { NULL },
        { NULL },
        { NULL },
        { NULL },
        { NULL },
        { NULL },
        { NULL },
        { "sizeof" } };
static int JavaCPP_offsets[10][2] = {
        { -1 },
        { -1 },
        { -1 },
        { -1 },
        { -1 },
        { -1 },
        { -1 },
        { -1 },
        { -1 },
        { sizeof(::std::vector<std::vector<void*> >) } };
static int JavaCPP_memberOffsetSizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

extern "C" {

JNIEXPORT int JavaCPP_init(int argc, const char *argv[]) {
#if defined(__ANDROID__) || TARGET_OS_IPHONE
    return JNI_OK;
#else
    if (JavaCPP_vm != NULL) {
        return JNI_OK;
    }
    int err;
    JavaVM *vm;
    JNIEnv *env;
    int nOptions = 1 + (argc > 255 ? 255 : argc);
    JavaVMOption options[256] = { { NULL } };
    options[0].optionString = (char*)"-Djava.class.path=javacpp.jar;H:/Data/Projects/MineRTX/src/main/java";
    for (int i = 1; i < nOptions && argv != NULL; i++) {
        options[i].optionString = (char*)argv[i - 1];
    }
    JavaVMInitArgs vm_args = { JNI_VERSION_1_6, nOptions, options };
    return (err = JNI_CreateJavaVM(&vm, (void**)&env, &vm_args)) == JNI_OK && vm != NULL && (err = JNI_OnLoad(vm, NULL)) >= 0 ? JNI_OK : err;
#endif
}

JNIEXPORT jint JNICALL JNI_OnLoad_jnijavacpp(JavaVM* vm, void* reserved);
JNIEXPORT void JNICALL JNI_OnUnload_jnijavacpp(JavaVM* vm, void* reserved);

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
    if (JNI_OnLoad_jnijavacpp(vm, reserved) == JNI_ERR) {
        return JNI_ERR;
    }
    JNIEnv* env;
    if (vm->GetEnv((void**)&env, JNI_VERSION_1_6) != JNI_OK) {
        JavaCPP_log("Could not get JNIEnv for JNI_VERSION_1_6 inside JNI_OnLoad().");
        return JNI_ERR;
    }
    if (JavaCPP_vm == vm) {
        return env->GetVersion();
    }
    JavaCPP_vm = vm;
    JavaCPP_haveAllocObject = env->functions->AllocObject != NULL;
    JavaCPP_haveNonvirtual = env->functions->CallNonvirtualVoidMethodA != NULL;
    jmethodID putMemberOffsetMID = JavaCPP_getStaticMethodID(env, 3, "putMemberOffset", "(Ljava/lang/String;Ljava/lang/String;I)Ljava/lang/Class;");
    if (putMemberOffsetMID == NULL) {
        return JNI_ERR;
    }
    for (int i = 0; i < 10 && !env->ExceptionCheck(); i++) {
        for (int j = 0; j < JavaCPP_memberOffsetSizes[i] && !env->ExceptionCheck(); j++) {
            if (env->PushLocalFrame(3) == 0) {
                jvalue args[3];
                args[0].l = env->NewStringUTF(JavaCPP_classNames[i]);
                args[1].l = JavaCPP_members[i][j] == NULL ? NULL : env->NewStringUTF(JavaCPP_members[i][j]);
                args[2].i = JavaCPP_offsets[i][j];
                jclass cls = (jclass)env->CallStaticObjectMethodA(JavaCPP_getClass(env, 3), putMemberOffsetMID, args);
                if (env->ExceptionCheck()) {
                    JavaCPP_log("Error putting member offsets for class %s.", JavaCPP_classNames[i]);
                    return JNI_ERR;
                }
                JavaCPP_classes[i] = cls == NULL ? NULL : (jclass)env->NewWeakGlobalRef(cls);
                if (env->ExceptionCheck()) {
                    JavaCPP_log("Error creating global reference of class %s.", JavaCPP_classNames[i]);
                    return JNI_ERR;
                }
                env->PopLocalFrame(NULL);
            }
        }
    }
    JavaCPP_addressFID = JavaCPP_getFieldID(env, 0, "address", "J");
    if (JavaCPP_addressFID == NULL) {
        return JNI_ERR;
    }
    JavaCPP_positionFID = JavaCPP_getFieldID(env, 0, "position", "J");
    if (JavaCPP_positionFID == NULL) {
        return JNI_ERR;
    }
    JavaCPP_limitFID = JavaCPP_getFieldID(env, 0, "limit", "J");
    if (JavaCPP_limitFID == NULL) {
        return JNI_ERR;
    }
    JavaCPP_capacityFID = JavaCPP_getFieldID(env, 0, "capacity", "J");
    if (JavaCPP_capacityFID == NULL) {
        return JNI_ERR;
    }
    JavaCPP_deallocatorFID = JavaCPP_getFieldID(env, 0, "deallocator", "Lorg/bytedeco/javacpp/Pointer$Deallocator;");
    if (JavaCPP_deallocatorFID == NULL) {
        return JNI_ERR;
    }
    JavaCPP_ownerAddressFID = JavaCPP_getFieldID(env, 2, "ownerAddress", "J");
    if (JavaCPP_ownerAddressFID == NULL) {
        return JNI_ERR;
    }
    JavaCPP_initMID = JavaCPP_getMethodID(env, 0, "init", "(JJJJ)V");
    if (JavaCPP_initMID == NULL) {
        return JNI_ERR;
    }
    JavaCPP_arrayMID = JavaCPP_getMethodID(env, 4, "array", "()Ljava/lang/Object;");
    if (JavaCPP_arrayMID == NULL) {
        return JNI_ERR;
    }
    JavaCPP_arrayOffsetMID = JavaCPP_getMethodID(env, 4, "arrayOffset", "()I");
    if (JavaCPP_arrayOffsetMID == NULL) {
        return JNI_ERR;
    }
    JavaCPP_bufferPositionFID = JavaCPP_getFieldID(env, 4, "position", "I");
    if (JavaCPP_bufferPositionFID == NULL) {
        return JNI_ERR;
    }
    JavaCPP_bufferLimitFID = JavaCPP_getFieldID(env, 4, "limit", "I");
    if (JavaCPP_bufferLimitFID == NULL) {
        return JNI_ERR;
    }
    JavaCPP_bufferCapacityFID = JavaCPP_getFieldID(env, 4, "capacity", "I");
    if (JavaCPP_bufferCapacityFID == NULL) {
        return JNI_ERR;
    }
    JavaCPP_stringMID = JavaCPP_getMethodID(env, 1, "<init>", "([B)V");
    if (JavaCPP_stringMID == NULL) {
        return JNI_ERR;
    }
    JavaCPP_getBytesMID = JavaCPP_getMethodID(env, 1, "getBytes", "()[B");
    if (JavaCPP_getBytesMID == NULL) {
        return JNI_ERR;
    }
    JavaCPP_toStringMID = JavaCPP_getMethodID(env, 5, "toString", "()Ljava/lang/String;");
    if (JavaCPP_toStringMID == NULL) {
        return JNI_ERR;
    }
    return env->GetVersion();
}

JNIEXPORT int JavaCPP_uninit() {
#if defined(__ANDROID__) || TARGET_OS_IPHONE
    return JNI_OK;
#else
    JavaVM *vm = JavaCPP_vm;
    JNI_OnUnload(JavaCPP_vm, NULL);
    return vm->DestroyJavaVM();
#endif
}

JNIEXPORT void JNICALL JNI_OnUnload(JavaVM* vm, void* reserved) {
    JNIEnv* env;
    if (vm->GetEnv((void**)&env, JNI_VERSION_1_6) != JNI_OK) {
        JavaCPP_log("Could not get JNIEnv for JNI_VERSION_1_6 inside JNI_OnUnLoad().");
        return;
    }
    for (int i = 0; i < 10; i++) {
        env->DeleteWeakGlobalRef((jweak)JavaCPP_classes[i]);
        JavaCPP_classes[i] = NULL;
    }
    JNI_OnUnload_jnijavacpp(vm, reserved);
    JavaCPP_vm = NULL;
}

JNIEXPORT jobject JNICALL Java_net_fabricmc_minevkr_jivix_VectorTest_00024PointerVectorVector_get__J(JNIEnv* env, jobject obj, jlong arg0) {
    ::std::vector<std::vector<void*> >* ptr = (::std::vector<std::vector<void*> >*)jlong_to_ptr(env->GetLongField(obj, JavaCPP_addressFID));
    if (ptr == NULL) {
        env->ThrowNew(JavaCPP_getClass(env, 6), "This pointer address is NULL.");
        return 0;
    }
    jlong position = env->GetLongField(obj, JavaCPP_positionFID);
    ptr += position;
    jobject rarg = NULL;
    void** rptr;
    jthrowable exc = NULL;
    try {
        VectorAdapter< void* > radapter(ptr->operator[](arg0));
        rptr = radapter;
        jlong rcapacity = (jlong)radapter.size;
        void* rowner = radapter.owner;
        void (*deallocator)(void*) = rowner != NULL ? &VectorAdapter< void* >::deallocate : 0;
        if (rptr != NULL) {
            rarg = JavaCPP_createPointer(env, 7);
            if (rarg != NULL) {
                JavaCPP_initPointer(env, rarg, rptr, rcapacity, rowner, deallocator);
            }
        }
    } catch (...) {
        exc = JavaCPP_handleException(env, 8);
    }

    if (exc != NULL) {
        env->Throw(exc);
    }
    return rarg;
}
JNIEXPORT jobject JNICALL Java_net_fabricmc_minevkr_jivix_VectorTest_00024PointerVectorVector_get__JJ(JNIEnv* env, jobject obj, jlong arg0, jlong arg1) {
    ::std::vector<std::vector<void*> >* ptr = (::std::vector<std::vector<void*> >*)jlong_to_ptr(env->GetLongField(obj, JavaCPP_addressFID));
    if (ptr == NULL) {
        env->ThrowNew(JavaCPP_getClass(env, 6), "This pointer address is NULL.");
        return 0;
    }
    jlong position = env->GetLongField(obj, JavaCPP_positionFID);
    ptr += position;
    jobject rarg = NULL;
    void* rptr;
    rptr = (*ptr)[arg0][arg1];
    if (rptr != NULL) {
        rarg = JavaCPP_createPointer(env, 0);
        if (rarg != NULL) {
            env->SetLongField(rarg, JavaCPP_addressFID, ptr_to_jlong(rptr));
        }
    }
    return rarg;
}
JNIEXPORT void JNICALL Java_net_fabricmc_minevkr_jivix_VectorTest_00024PointerVectorVector_put__JJLorg_bytedeco_javacpp_Pointer_2(JNIEnv* env, jobject obj, jlong arg0, jlong arg1, jobject arg2) {
    ::std::vector<std::vector<void*> >* ptr = (::std::vector<std::vector<void*> >*)jlong_to_ptr(env->GetLongField(obj, JavaCPP_addressFID));
    if (ptr == NULL) {
        env->ThrowNew(JavaCPP_getClass(env, 6), "This pointer address is NULL.");
        return;
    }
    jlong position = env->GetLongField(obj, JavaCPP_positionFID);
    ptr += position;
    char* ptr2 = arg2 == NULL ? NULL : (char*)jlong_to_ptr(env->GetLongField(arg2, JavaCPP_addressFID));
    jlong position2 = arg2 == NULL ? 0 : env->GetLongField(arg2, JavaCPP_positionFID);
    ptr2 += position2;
    (*ptr)[arg0][arg1] = ptr2;
}
JNIEXPORT jobject JNICALL Java_net_fabricmc_minevkr_jivix_VectorTest_00024PointerVectorVector_put__Lnet_fabricmc_minevkr_jivix_VectorTest_00024PointerVectorVector_2(JNIEnv* env, jobject obj, jobject arg0) {
    ::std::vector<std::vector<void*> >* ptr = (::std::vector<std::vector<void*> >*)jlong_to_ptr(env->GetLongField(obj, JavaCPP_addressFID));
    if (ptr == NULL) {
        env->ThrowNew(JavaCPP_getClass(env, 6), "This pointer address is NULL.");
        return 0;
    }
    jlong position = env->GetLongField(obj, JavaCPP_positionFID);
    ptr += position;
    ::std::vector<std::vector<void*> >* ptr0 = arg0 == NULL ? NULL : (::std::vector<std::vector<void*> >*)jlong_to_ptr(env->GetLongField(arg0, JavaCPP_addressFID));
    if (ptr0 == NULL) {
        env->ThrowNew(JavaCPP_getClass(env, 6), "Pointer address of argument 0 is NULL.");
        return 0;
    }
    jlong position0 = arg0 == NULL ? 0 : env->GetLongField(arg0, JavaCPP_positionFID);
    ptr0 += position0;
    jobject rarg = NULL;
    ::std::vector<std::vector<void*> >* rptr;
    jthrowable exc = NULL;
    try {
        rptr = &((*ptr)=(*ptr0));
        if (rptr == ptr) {
            rarg = obj;
        } else if (rptr != NULL) {
            rarg = JavaCPP_createPointer(env, 9);
            if (rarg != NULL) {
                env->SetLongField(rarg, JavaCPP_addressFID, ptr_to_jlong(rptr));
            }
        }
    } catch (...) {
        exc = JavaCPP_handleException(env, 8);
    }

    if (exc != NULL) {
        env->Throw(exc);
    }
    return rarg;
}
JNIEXPORT jlong JNICALL Java_net_fabricmc_minevkr_jivix_VectorTest_00024PointerVectorVector_size__J(JNIEnv* env, jobject obj, jlong arg0) {
    ::std::vector<std::vector<void*> >* ptr = (::std::vector<std::vector<void*> >*)jlong_to_ptr(env->GetLongField(obj, JavaCPP_addressFID));
    if (ptr == NULL) {
        env->ThrowNew(JavaCPP_getClass(env, 6), "This pointer address is NULL.");
        return 0;
    }
    jlong position = env->GetLongField(obj, JavaCPP_positionFID);
    ptr += position;
    jlong rarg = 0;
    jthrowable exc = NULL;
    try {
        jlong rval = (*ptr)[arg0].size();
        rarg = (jlong)rval;
    } catch (...) {
        exc = JavaCPP_handleException(env, 8);
    }

    if (exc != NULL) {
        env->Throw(exc);
    }
    return rarg;
}
JNIEXPORT jlong JNICALL Java_net_fabricmc_minevkr_jivix_VectorTest_00024PointerVectorVector_size__(JNIEnv* env, jobject obj) {
    ::std::vector<std::vector<void*> >* ptr = (::std::vector<std::vector<void*> >*)jlong_to_ptr(env->GetLongField(obj, JavaCPP_addressFID));
    if (ptr == NULL) {
        env->ThrowNew(JavaCPP_getClass(env, 6), "This pointer address is NULL.");
        return 0;
    }
    jlong position = env->GetLongField(obj, JavaCPP_positionFID);
    ptr += position;
    jlong rarg = 0;
    jthrowable exc = NULL;
    try {
        jlong rval = ptr->size();
        rarg = (jlong)rval;
    } catch (...) {
        exc = JavaCPP_handleException(env, 8);
    }

    if (exc != NULL) {
        env->Throw(exc);
    }
    return rarg;
}
JNIEXPORT jboolean JNICALL Java_net_fabricmc_minevkr_jivix_VectorTest_00024PointerVectorVector_empty__J(JNIEnv* env, jobject obj, jlong arg0) {
    ::std::vector<std::vector<void*> >* ptr = (::std::vector<std::vector<void*> >*)jlong_to_ptr(env->GetLongField(obj, JavaCPP_addressFID));
    if (ptr == NULL) {
        env->ThrowNew(JavaCPP_getClass(env, 6), "This pointer address is NULL.");
        return 0;
    }
    jlong position = env->GetLongField(obj, JavaCPP_positionFID);
    ptr += position;
    jboolean rarg = 0;
    jthrowable exc = NULL;
    try {
        bool rval = (bool)(*ptr)[arg0].empty();
        rarg = (jboolean)rval;
    } catch (...) {
        exc = JavaCPP_handleException(env, 8);
    }

    if (exc != NULL) {
        env->Throw(exc);
    }
    return rarg;
}
JNIEXPORT jboolean JNICALL Java_net_fabricmc_minevkr_jivix_VectorTest_00024PointerVectorVector_empty__(JNIEnv* env, jobject obj) {
    ::std::vector<std::vector<void*> >* ptr = (::std::vector<std::vector<void*> >*)jlong_to_ptr(env->GetLongField(obj, JavaCPP_addressFID));
    if (ptr == NULL) {
        env->ThrowNew(JavaCPP_getClass(env, 6), "This pointer address is NULL.");
        return 0;
    }
    jlong position = env->GetLongField(obj, JavaCPP_positionFID);
    ptr += position;
    jboolean rarg = 0;
    jthrowable exc = NULL;
    try {
        bool rval = (bool)ptr->empty();
        rarg = (jboolean)rval;
    } catch (...) {
        exc = JavaCPP_handleException(env, 8);
    }

    if (exc != NULL) {
        env->Throw(exc);
    }
    return rarg;
}
JNIEXPORT jobject JNICALL Java_net_fabricmc_minevkr_jivix_VectorTest_00024PointerVectorVector_at(JNIEnv* env, jobject obj, jlong arg0) {
    ::std::vector<std::vector<void*> >* ptr = (::std::vector<std::vector<void*> >*)jlong_to_ptr(env->GetLongField(obj, JavaCPP_addressFID));
    if (ptr == NULL) {
        env->ThrowNew(JavaCPP_getClass(env, 6), "This pointer address is NULL.");
        return 0;
    }
    jlong position = env->GetLongField(obj, JavaCPP_positionFID);
    ptr += position;
    jobject rarg = NULL;
    void** rptr;
    jthrowable exc = NULL;
    try {
        VectorAdapter< void* > radapter(ptr->at(arg0));
        rptr = radapter;
        jlong rcapacity = (jlong)radapter.size;
        void* rowner = radapter.owner;
        void (*deallocator)(void*) = rowner != NULL ? &VectorAdapter< void* >::deallocate : 0;
        if (rptr != NULL) {
            rarg = JavaCPP_createPointer(env, 7);
            if (rarg != NULL) {
                JavaCPP_initPointer(env, rarg, rptr, rcapacity, rowner, deallocator);
            }
        }
    } catch (...) {
        exc = JavaCPP_handleException(env, 8);
    }

    if (exc != NULL) {
        env->Throw(exc);
    }
    return rarg;
}
JNIEXPORT void JNICALL Java_net_fabricmc_minevkr_jivix_VectorTest_00024PointerVectorVector_resize__JJ(JNIEnv* env, jobject obj, jlong arg0, jlong arg1) {
    ::std::vector<std::vector<void*> >* ptr = (::std::vector<std::vector<void*> >*)jlong_to_ptr(env->GetLongField(obj, JavaCPP_addressFID));
    if (ptr == NULL) {
        env->ThrowNew(JavaCPP_getClass(env, 6), "This pointer address is NULL.");
        return;
    }
    jlong position = env->GetLongField(obj, JavaCPP_positionFID);
    ptr += position;
    jthrowable exc = NULL;
    try {
        (*ptr)[arg0].resize(arg1);
    } catch (...) {
        exc = JavaCPP_handleException(env, 8);
    }

    if (exc != NULL) {
        env->Throw(exc);
    }
}
JNIEXPORT void JNICALL Java_net_fabricmc_minevkr_jivix_VectorTest_00024PointerVectorVector_resize__J(JNIEnv* env, jobject obj, jlong arg0) {
    ::std::vector<std::vector<void*> >* ptr = (::std::vector<std::vector<void*> >*)jlong_to_ptr(env->GetLongField(obj, JavaCPP_addressFID));
    if (ptr == NULL) {
        env->ThrowNew(JavaCPP_getClass(env, 6), "This pointer address is NULL.");
        return;
    }
    jlong position = env->GetLongField(obj, JavaCPP_positionFID);
    ptr += position;
    jthrowable exc = NULL;
    try {
        ptr->resize(arg0);
    } catch (...) {
        exc = JavaCPP_handleException(env, 8);
    }

    if (exc != NULL) {
        env->Throw(exc);
    }
}
JNIEXPORT void JNICALL Java_net_fabricmc_minevkr_jivix_VectorTest_00024PointerVectorVector_allocate__(JNIEnv* env, jobject obj) {
    jthrowable exc = NULL;
    try {
        ::std::vector<std::vector<void*> >* rptr = new ::std::vector<std::vector<void*> >();
        jlong rcapacity = 1;
        JavaCPP_initPointer(env, obj, rptr, rcapacity, rptr, &JavaCPP_net_fabricmc_minevkr_jivix_VectorTest_00024PointerVectorVector_deallocate);
    } catch (...) {
        exc = JavaCPP_handleException(env, 8);
    }

    if (exc != NULL) {
        env->Throw(exc);
    }
}
JNIEXPORT void JNICALL Java_net_fabricmc_minevkr_jivix_VectorTest_00024PointerVectorVector_allocate__J(JNIEnv* env, jobject obj, jlong arg0) {
    jthrowable exc = NULL;
    try {
        ::std::vector<std::vector<void*> >* rptr = new ::std::vector<std::vector<void*> >(arg0);
        jlong rcapacity = 1;
        JavaCPP_initPointer(env, obj, rptr, rcapacity, rptr, &JavaCPP_net_fabricmc_minevkr_jivix_VectorTest_00024PointerVectorVector_deallocate);
    } catch (...) {
        exc = JavaCPP_handleException(env, 8);
    }

    if (exc != NULL) {
        env->Throw(exc);
    }
}


}

