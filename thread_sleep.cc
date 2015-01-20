/*********************************************************************
 * NAN - Native Abstractions for Node.js
 *
 * Copyright (c) 2014 NAN contributors
 *
 * MIT License <https://github.com/rvagg/nan/blob/master/LICENSE.md>
 ********************************************************************/
#include <nan.h>
#include <ctime>

using v8::FunctionTemplate;
using v8::Handle;
using v8::Object;
using v8::String;
using v8::Number;

// Simple synchronous access to the `Estimate()` function
NAN_METHOD(SleepSync) {
  NanScope();

  // expect a number as the first argument
  int milisec = args[0]->Uint32Value();

  struct timespec req;
  req.tv_sec = milisec / 1000;
  req.tv_nsec = (milisec % 1000) * 1000000L;
  nanosleep(&req, (struct timespec *)NULL);

  NanReturnValue(NanNew<Number>(milisec));
}



// Expose synchronous and asynchronous access to our
// Estimate() function
void InitAll(Handle<Object> exports) {
  exports->Set(NanNew<String>("sleep"),
    NanNew<FunctionTemplate>(SleepSync)->GetFunction());
}

NODE_MODULE(thread_sleep, InitAll)
