#! /bin/bash

url="http://www.ovh.net/files/1Mio.dat"
curl -I ${url}
curl ${url} -O
curl ${url} -o download
curl ${url} > download2