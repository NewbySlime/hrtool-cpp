# hrtool-cpp

Tool dibuat untuk pengetesan soal hackerrank khusus untuk c++.

## Usage
Tinggal masukkan filenya kedalam folder hackerrank.

Kemudian pakai makefile agar compiling secara otomatis.

```bash
mingw32-make InputF="Path/ke/file" OutputF="Path/ke/file" srccpp="Path/ke/src/code"
```

* InputF: file testcase input dari hackerrank
* OutputF: file testcase output dari hackerrank, agar dibandingkan dengan output aslinya
* srccpp: file source code yang anda pakai di solusi hackerrank

"make"-nya disesuaikan.

**Note: path-nya jangan ditambah spasi.**

## Contoh
```bash
mingw32-make InputF="./input/Input_deque-stl5.txt" OutputF="./output/Output_deque-stl5.txt" srccpp="./src/deque_stl.cpp"
```
