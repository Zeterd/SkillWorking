package main

import "fmt"

func main() {
    //Existe tres maneiras de declarar variaveis    
    var i int = 42
    
    var j float32
    j = 45

    k := 23

    //Quando nao se atribui valor, o Go automaticamente mete o valor a 0
    var zero int

    fmt.Printf("%v, %T\n", i, i)
    fmt.Printf("%v, %T\n", j, j)
    fmt.Printf("%v, %T\n", k, k)
    fmt.Printf("%v, %T\n", zero, zero)

    //Booleans
    var b1 bool
    fmt.Printf("%v, %T\n", b1, b1)

    b2 := 4==5
    fmt.Printf("%v, %T\n", b2, b2)

    //Tipos com tamanho
    //INT
    // var i8 int8
    // var i16 int16
    // var i32 int32
    // var i64 int64

    //UINT
    // var u8 uint8
    // var u16 uint16
    // var u32 uint32
    
    //FLOAT
    // var f32 float32
    // var f64 float64

    //COMPLEX
    var compl complex64 = 1 + 2i
    fmt.Printf("%v, %T\n", compl, compl)
    fmt.Printf("%v, %T\n", real(compl), real(compl))
    fmt.Printf("%v, %T\n", imag(compl), imag(compl))

    var compl2 complex128 = complex(2, 5)
    fmt.Printf("%v, %T\n", compl2, compl2)


    //OPERACOES
    a := 10
    b := 5

    fmt.Println(a+b)
    fmt.Println(a*b)
    fmt.Println(a/b)
    fmt.Println(float32(a/b))
    fmt.Println(a%b)

    //BINARIO
    // a: 1010
    // b: 0101

    fmt.Println(a & b) // AND:    0000 = 0
    fmt.Println(a | b) // OR:     1111 = 15
    fmt.Println(a ^ b) // XOR:    1111 = 15
    fmt.Println(a &^ b)// NOT OR: 0000 = 0

    //BIT SHIFTING
    
    c := 8 // 2^3

    fmt.Println(c << 3) // 2^3 * 2^3 = 2^6
    fmt.Println(c >> 3) // 2^3 / 2^3 = 2^0

    //STRINGS
    var s string = "This is a string"
    fmt.Printf("%v, %T\n", s, s)

    fmt.Printf("%v, %T\n", string(s[2]), s[2])

    s2 := " and this is also a string"
    fmt.Printf("%v, %T\n", s+s2, s+s2)

    //Go e como o C em que muda os valores ASCII dos caracters

    by := []byte(s)
    //Imprime os valores de cada caracter ASCII em int em formato array
    fmt.Printf("%v, %T\n", by, by) 


    









}
