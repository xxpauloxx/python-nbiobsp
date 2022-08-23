#!/usr/bin/env python

import pynbiobsp as pnbio
pnbio.init()

pnbio.devices()

print('Insert the first fingerprint: ')
fir1 = pnbio.capture()

print('Insert the second fingerprint: ')
fir2 = pnbio.capture()

if pnbio.match(fir1, fir2):
    print('OK!')
else:
    print('NOK!')

pnbio.close()