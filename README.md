# Aplikasi CFG dan PDA pada Pengenalan Ekspresi Matematika

Pada tugas kedua TBFO ini, diminta untuk membuat sebuah kalkulator sederhana yang menggunakan implementasi 
tata bahasa bebas konteks (CFG) dan/atau PushDown Automata (PDA). Bila Kalkulator diberikan sebuah ekspresi
matematika, program harus bisa mengenali apakah ekspresi matematika tersebut valid atau tidak (syntax error).
Bila ekspresi tersebut valid, program akan menghitung nilai dari ekspresi tersebut dengan mengubah terlebih
dahulu setiap simbol terminal (angka) menjadi nilai numerik yang bersesuaian. Program juga harus dapat mengenali
apakah ekspresi tersebut mungkin dihitung atau tidak (math error).

## How to run

Windows user:
```
user> gcc -std=c11 -o gcc -std=c11 -o main main.c stack.c mesintoken.c pda.c stackchar.c
user> main
```

Linux user:
```
$ gcc -std=c11 -o gcc -std=c11 -o main main.c stack.c mesintoken.c pda.c stackchar.c
$ ./main
```
