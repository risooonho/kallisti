from distutils.core import setup, Extension
import os

def flags_to_names(flags, arg):
    """Convert a string containing compiler flags into a list of include
       directories. """
    includes=[]
    for i in flags.split():
        if i[:2] == arg:
            includes.append(i[2:])
    return includes

eris_cflags = os.popen('pkg-config --cflags-only-I eris-1.3').read()
eris_includes = flags_to_names(eris_cflags, '-I')

eris_link = os.popen('pkg-config --libs eris-1.3').read()
eris_libs = flags_to_names(eris_link, '-l')

atlas = Extension('atlas', sources=['atlas.cpp'], language='c++')
eris = Extension('eris', sources=['eris.cpp',
                                  'eris_connection.cpp'],
                  include_dirs=eris_includes,
                  libraries=eris_libs,
                  language='c++')

setup (name = 'Kallisti',
       version = '0.0.0',
       description = 'Wrapper for WorldForge C++ libraries',
       author = 'Alistair Riddoch',
       author_email = 'alriddoch@worldforge.org',
       url = 'http://www.worldforge.org/dev/eng/libraries/',
       long_description = """
This package contains a number of modules which wrap the core WorldForge C++
libraries required to build usable components of the WorldForge system.
""",
       ext_modules = [atlas, eris])
       