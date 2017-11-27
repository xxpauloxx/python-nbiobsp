#!/usr/bin/env python

import pynbiobsp as pnbio
pnbio.init()

print('Insert the first fingerprint: ')
fir1 = pnbio.capture(10000)

print('Insert the second fingerprint: ')
fir2 = pnbio.capture(10000)

if pnbio.match(fir1, fir2):
    print('OK!')
else:
    print('NOK!')

pnbio.close()