# NBioBSP Module for Python

Digital fingerprint reader module for Python using Nitgen device.
Install the driver that is the "driver" directory.

## Acknowledgments


Agradeço a [Fingertech](http://www.fingertech.com.br) por todo apoio, suporte e investimento, 
sem essa parceria não seria possível manter esse projeto.
<br />

Thanks to [Fingertech](http://www.fingertech.com.br) for all support and investment,
without this partnership it would not be possible to maintain this project.


## Install Nitgen Hamster driver

```bash

$ sudo apt-get install g++ gcc linux-headers build-essential make  python-dev autotools-dev libicu-dev libbz2-dev libboost-all-dev libboost-python-dev 
$ git clone https://github.com/paulopinda/python-nbiobsp.git
$ cd python-nbiobsp
$ cd driver
$ sudo cp libNBioBSP.so NBioBSP.lic /lib
$ tar -xzvf <ngstardrv-v1.0.5-1-Ubuntu14.04-32bit-2015.03.18.tgz> or <ngstardrv-v1.0.5-2-Ubuntu14.04-64bit-2015.03.30.tgz>
$ cd <ngstardrv-v1.0.5-1-Ubuntu14.04-32bit> or <ngstardrv-v1.0.5-2-Ubuntu14.04-64bit>
$ ./CreateModule
$ sudo ./install.sh

```


## Install Python Module

Need change BOOSTPYTHON_VERSION in the setup.py to your version Python. 

```bash

$ git clone https://github.com/paulopinda/python-nbiobsp.git
$ cd python-nbiobsp
$ python setup.py build
$ python setup.py install

```

### Example

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


## Message: 'required key not available'
I had a problem loading kernel module and the following message appeared: 
'required key not available'. I used mokutil to disable safe boot mode.

```bash
$ sudo mokutil --disable-validation
```


## Contribute

If anything is missing from the code or the README.md documentation, please send me a PULL REQUEST.