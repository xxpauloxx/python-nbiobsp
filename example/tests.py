
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