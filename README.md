# NBioBSP Module for Python

Digital fingerprint reader module for Python using Nitgen device.
Install the driver that is the "driver" directory.

```bash
git clone https://github.com/paulopinda/python-nbiobsp.git
cd python-nbiobsp
python setup.py build
python setup.py install
```
#### Simple code

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

PS: Need change BOOSTPYTHON_VERSION in the setup.py to your version Python.

