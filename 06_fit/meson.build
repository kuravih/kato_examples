threads_dep = dependency('threads')

lib_include = include_directories('../lib')

executable(
    '06_fit',
    'main.cpp',
    include_directories : lib_include,
    dependencies : threads_dep,
    install : false
)