# Módulo NBioBSP Python

Módulo para utilização do leitor biométrico Nitgen Hamster III em Python. Faça a instalação do driver que está no diretório driver(64 bits, mas existe 32 bits na Internet também).

```bash
git clone https://github.com/izepa/python-nbiobsp-module.git
cd python-nbiobsp-module
python setup.py build
python setup.py install
```
#### Código para testar o módulo.

```python

import time 
import pynbiobsp as pnbio
pnbio.init()

print('Posicione a primeira digital: ')
time.sleep(1)
fir1 = pnbio.capture(5000)

print('Posicione a segunda digital: ')
time.sleep(1)
fir2 = pnbio.capture(5000)

if pnbio.match(fir1, fir2):
    print('Digitais correspondem!')
else:
    print('Digitais não correspondem.')

pnbio.close()

```