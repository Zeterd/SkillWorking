import sys
from bitstring import Bits
from bitstring import ConstBitStream
from math import log2
from math import ceil

def main():
    if len(sys.argv) > 2:
        file = open(sys.argv[1], "r")
        fileOUT = open(sys.argv[2], "a")
        msg = ConstBitStream(Bits(file))
        msg = Bits(file).bin
    else:
        msg = '%$"##$"%$#&%$/&(&/)/()(%$&#'
    
    keys = ['E']
    output = ''
    elemt = 'E'

    for i in msg:
        elemt = str(elemt+i)
        
        if elemt[1:] not in keys:
            print("dictonary: %s " % keys)
            n = ceil(log2(len(keys)))
            print("n: %i " % n)

            #x = output = yb
            y = elemt[:-1]
            b = elemt[-1:]            

            
            y = y.replace('E', '')
            b = b.replace('E', '')
            
            keys.append(str(y)+str(b))

            if y == '':
                y = 'E'

            print("y: %s " % y)
            print("b: %s " % b)

            pos = keys.index(y)

            pos_bin = ('{0:0' + str(n) + 'b}').format(pos)

            print("pos_bin: %s " % pos_bin)

            
            if n == 0:
                output = output + str(b)
            else:
                output = output + ( str(pos_bin) + str(b) )
            
            if len(sys.argv) > 2 :
                fileOUT.write(output)

            print("output: %s " % output)

            elemt = 'E'
    if len(elemt[0:]) != 0:
        output = output + elemt[1:]
        if len(sys.argv) > 2 :
            fileOUT.write(output)

    if len(sys.argv) > 2 :
        file.close()
        fileOUT.close()
    print(keys)
    print("OUTPUT FINAL CARALHO: %s" % output)
    print(len(output))



if __name__ == "__main__":
    main()
