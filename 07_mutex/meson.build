threads_dep = dependency('threads')

lib_include = include_directories('../lib')

executable(
    '07_mutex',
    'main.cpp',
    include_directories : lib_include,
    dependencies : threads_dep,
    install : false
)