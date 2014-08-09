package main

import "fmt"
import "os"

func main() {
    N,M,P:=0,0,0


    fmt.Scanf("%d %d",&N,&M)
    fmt.Scanf("%d",&P)

    PAx,PAy,PBx,PBy:=1,1,N,M

    for i:=0;i<P;i++ {
        ma,mb:=0,0
        fmt.Scanf("%d %d",&ma,&mb)
        //1 (Norte), 2 (Sul), 3 (Leste) e 4 (Oeste)
        switch ma {
            case 1:
                PAy++
            case 2:
                PAy--
            case 3:
                PAx++
            case 4:
                PAx--
        }
        switch mb {
            case 1:
                PBy++
            case 2:
                PBy--
            case 3:
                PBx++
            case 4:
                PBx--
        }
        if PAx < 1 || PAy < 1 || PAx > N || PAy > M {
            fmt.Printf("PA saiu na posicao (%d,%d) no passo %d\n",PAx,PAy,i+1)
            os.Exit(0)
        }
        if PBx < 1 || PBy < 1 || PBx > N || PBy > M {
            fmt.Printf("PB saiu na posicao (%d,%d) no passo %d\n",PBx,PBy,i+1)
            os.Exit(0)
        }
        if PAx == PBx && PAy == PBy {
            fmt.Printf("Encontraram-se na posicao (%d,%d) no passo %d\n",PAx,PAy,i+1)
            os.Exit(0)
        }
    }
    fmt.Printf("Nao se encontraram\n")
}
