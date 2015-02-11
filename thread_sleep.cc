/*********************************************************************
 * thread-sleep: Force Node.js to sleep
 *
 * Copyright (c) 2015 Forbes Lindesay
 * Copyright (c) 2015 Tiancheng "Timothy" Gu
 *
 * MIT License
 ********************************************************************/
#include <nan.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <ctime>
#endif

using v8::FunctionTemplate;
using v8::Handle;
using v8::Object;
using v8::String;
using v8::Number;

NAN_METHOD(SleepSync) {
  NanScope();

  // expect a number as the first argument
  int milisec = args[0]->Uint32Value();

#ifdef _WIN32
  Sleep(milisec);
#else
  struct timespec req;
  req.tv_sec = milisec / 1000;
  req.tv_nsec = (milisec % 1000) * 1000000L;
  nanosleep(&req, (struct timespec *)NULL);
#endif

  NanReturnValue(NanNew<Number>(milisec));
}

// Expose SleepSync() as sleep() in JS
void InitAll(Handle<Object> exports) {
  exports->Set(NanNew<String>("sleep"),
    NanNew<FunctionTemplate>(SleepSync)->GetFunction());
}

NODE_MODULE(thread_sleep, InitAll)
