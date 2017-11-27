#!/usr/bin/env python

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