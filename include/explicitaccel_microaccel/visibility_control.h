#ifndef EXPLICITACCEL_MICROACCEL__VISIBILITY_CONTROL_H_
#define EXPLICITACCEL_MICROACCEL__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define EXPLICITACCEL_MICROACCEL_EXPORT __attribute__ ((dllexport))
    #define EXPLICITACCEL_MICROACCEL_IMPORT __attribute__ ((dllimport))
  #else
    #define EXPLICITACCEL_MICROACCEL_EXPORT __declspec(dllexport)
    #define EXPLICITACCEL_MICROACCEL_IMPORT __declspec(dllimport)
  #endif
  #ifdef EXPLICITACCEL_MICROACCEL_BUILDING_LIBRARY
    #define EXPLICITACCEL_MICROACCEL_PUBLIC EXPLICITACCEL_MICROACCEL_EXPORT
  #else
    #define EXPLICITACCEL_MICROACCEL_PUBLIC EXPLICITACCEL_MICROACCEL_IMPORT
  #endif
  #define EXPLICITACCEL_MICROACCEL_PUBLIC_TYPE EXPLICITACCEL_MICROACCEL_PUBLIC
  #define EXPLICITACCEL_MICROACCEL_LOCAL
#else
  #define EXPLICITACCEL_MICROACCEL_EXPORT __attribute__ ((visibility("default")))
  #define EXPLICITACCEL_MICROACCEL_IMPORT
  #if __GNUC__ >= 4
    #define EXPLICITACCEL_MICROACCEL_PUBLIC __attribute__ ((visibility("default")))
    #define EXPLICITACCEL_MICROACCEL_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define EXPLICITACCEL_MICROACCEL_PUBLIC
    #define EXPLICITACCEL_MICROACCEL_LOCAL
  #endif
  #define EXPLICITACCEL_MICROACCEL_PUBLIC_TYPE
#endif
#endif  // EXPLICITACCEL_MICROACCEL__VISIBILITY_CONTROL_H_
// Generated 13-Nov-2022 18:38:36
// Copyright 2019-2020 The MathWorks, Inc.
