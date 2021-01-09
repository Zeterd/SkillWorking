import sys
from bitstring import Bits, ConstBitStream, BitArray, ReadError
from math import log2
from math import ceil

def main():
    file = open(sys.argv[1], "rb")
    msg = ConstBitStream(file)

    s_in = BitArray()
    aux = BitArray()
    keys = ['']
    s_out = ''

    s_in.append(msg.read(1))
    aux = s_in.copy()
    aux.invert(0)
    count = 0

    #Encontrar o tamanho do padding
    while (s_in.bin) != aux.bin:
        try:
            count += 1
            s_in.clear()
            s_in.append(msg.read(1))
           
            
        except ReadError:
            break

    padding = BitArray()
    padding.append(s_in)

    s_in = BitArray()
    
    #Com o tamanho encontrar o padding correspondente
    padding.append(msg.read(count-1))

    while True:
        n_bits = ceil(log2(len(keys)))
        
        try: 
            s_in.append(msg.read(n_bits+1))
        except ReadError:
            break

        y = s_in[:-1]
        b = s_in[-1:]

        if Bits(y) == Bits(''):
            pos = 0
        else:
            pos = y.uint
        
        s_out = s_out + (str(keys[pos])+b.bin)
        
        keys.append(str(keys[pos])+str(Bits(b).bin))
        
        s_in = BitArray()
        
    output = BitArray('0b'+s_out)
    output.append(padding)
    
    with open(sys.argv[2], 'wb') as f_out:
        output.tofile(f_out)

    file.close()

if __name__ == "__main__":
    main()
