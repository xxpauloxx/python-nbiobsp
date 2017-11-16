#!/usr/bin/env python

from distutils.core import setup
from distutils.extension import Extension

from distutils.unixccompiler import UnixCCompiler
import distutils.sysconfig
old_init_posix = distutils.sysconfig._init_posix

def _init_posix():
    old_init_posix()
    distutils.sysconfig._config_vars['LDSHARED'] = 'g++ -shared'
    distutils.sysconfig._config_vars['CC'] = 'g++'

distutils.sysconfig._init_posix = _init_posix


BOOSTPYTHON_VERSION = 'boost_python-py35'

setup(name="pynbiobsp",
      version = '0.1',
      description = 'Fingerprint module for nitgen hamster',
      author = 'Paulo R. Silva',
      author_email = 'paulo.pinda@gmail.com',
      url = 'https://github.com/paulopinda/python-nbiobsp/',
  	  ext_modules=[
  	       Extension("pynbiobsp", ["pynbiobsp.cpp"],
  	       libraries = [BOOSTPYTHON_VERSION, 'NBioBSP'])
  	  ])

