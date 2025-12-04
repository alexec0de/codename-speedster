[![GPLv3 License](https://img.shields.io/badge/License-GPL%20v3-yellow.svg)](https://opensource.org/licenses/)
![Repo Stars](https://img.shields.io/github/stars/AcronixOS-Inc/codename-speedster)
![Repo Forks](https://img.shields.io/github/forks/AcronixOS-Inc/codename-speedster)
![Releases](https://img.shields.io/github/v/release/AcronixOS-Inc/codename-speedster)


<h3 align="center">LibreAcronium</h3>

<h3 align="center">
  <img width="800" style="border-radius:5px;" alt="screenshot" src="screenshots/25.06.23-stable.png">
</h3>

# LibreAcronium (codename speedster)

LibreAcronium — это современное экспериментальное ядро операционной системы, разрабатываемое с целью исследования низкоуровневых технологий, обучения системному программированию и тестирования новых концепций в области ОС
## Быстрый старт

```
git clone https://github.com/AcronixOS-INC/codename-speedster.git
cd codename-speedster
make all
make run
```
## Зависимости

```
# Debian/Ubuntu
sudo apt-get install build-essential nasm gcc-multilib qemu-system-x86 gdb
```

```
# Arch Linux
sudo pacman -S base-devel nasm qemu gdb gcc-multilib
```

```
# Fedora/RHEL
sudo dnf install @development-tools nasm qemu gdb
```

```
# Альт Линукс (Сизиф)
su -
apt-get install nasm qemu gdb gcc
```

## Лицензия

Этот репозиторий, включая все его содержимое, подпроекты, модули и компоненты, лицензирован в соответствии с [GNU GPL v3](https://www.gnu.org/licenses/gpl-3.0.txt), если явно не указано иное. Сторонние библиотеки, включенные в этот репозиторий, могут подчиняться их собственным лицензиям.