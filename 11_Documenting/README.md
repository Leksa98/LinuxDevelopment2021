# Сборка
```sh
meson build 
cd build
meson compile
```
# Создание документации

```sh
meson compile documentation 
```
# Удаление генератов

```sh
rm -rf build  
```
# Запуск на английском
```sh
LC_ALL=en_US ./build/guess
или
./build/guess
```
# Запуск на русском
```sh
LC_ALL=ru_RU ./build/guess 
```
