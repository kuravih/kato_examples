threads_dep = dependency('threads')

lib_include = include_directories('../lib')

executable(
    '04_sleep',
    'main.cpp',
    include_directories : lib_include,
    dependencies : threads_dep,
    install : false
)