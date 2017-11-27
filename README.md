# Nitgen Hamster III Module for Python 2.7.x and 3.x

Digital fingerprint reader module for Python using Nitgen device.
Install the driver that is the "driver" directory.

## Acknowledgments

Thanks to [Fingertech](http://www.fingertech.com.br) for all support and investment,
without this partnership it would not be possible to maintain this project.


## Install Nitgen Hamster driver

```bash

$ sudo apt-get install g++ gcc linux-headers build-essential make  python-dev autotools-dev libicu-dev libbz2-dev
$ git clone https://github.com/paulopinda/python-nbiobsp.git
$ cd python-nbiobsp
$ cd utils/libs

$ # Install libs
$ sudo cp NBioBSP.lic /lib
$ sudo cp libs/linux_<x86_x64/x86>/libNBioBSP.so /lib

$ # Install driver
$ cd hamster-iii
$ tar -xzvf ngstardrv-...# choose 32 or 64bits
$ cd ngstardrv-...
$ ./CreateModule
$ sudo ./install.sh

```

## Message: 'required key not available'

I had a problem loading kernel module and the following message appeared: 
'required key not available'. I used mokutil to disable secure boot mode.

```bash
$ sudo mokutil --disable-validation
```

Reboot and change boot state.

## Install from Pypi

```bash

$ pip install pynbiobsp

```

## Install from Github

```bash

$ git clone https://github.com/paulopinda/python-nbiobsp.git
$ cd python-nbiobsp
$ pip install pybind11
$ python setup.py build install

```

## Example

Simple example who capture two fingerprints and validate.

```python
import time
import pynbiobsp as pnbio
pnbio.init()

print('Insert the first fingerprint: ')
time.sleep(1)
fir1 = pnbio.capture(5000)

print('Insert the second fingerprint: ')
time.sleep(1)
fir2 = pnbio.capture(5000)

if pnbio.match(fir1, fir2):
    print('OK!')
else:
    print('NOK!')

pnbio.close()
```

## Contribute

If anything is missing from the code or the README.md documentation, please send me a PULL REQUEST.