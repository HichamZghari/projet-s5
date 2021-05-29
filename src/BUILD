load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "build",
    srcs = glob(["*.c"],
      	 exclude = ["test.c"]),
    hdrs = glob(["*.h"]),
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "project",
    
    srcs = ["project-0.c"],
    deps = [
    	":build",
    ],
)
