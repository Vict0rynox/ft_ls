
usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]

https://www.opennet.ru/cgi-bin/opennet/man.cgi?topic=lstat

* S_ISLNK(file_stat->st_mode)) ->  символьной ссылкой (Нет в POSIX.1-1996.)
* S_ISREG(file_stat->st_mode)) ->	обычным файлом
* S_ISCHR(file_stat->st_mode)) ->	символьным устройством
* S_ISDIR(file_stat->st_mode)) ->	каталогом
* S_ISBLK(file_stat->st_mode)) ->  блочным устройством
* S_ISFIFO(file_stat->st_mode)) ->	каналом FIFO®
* S_ISSOCK(file_stat->st_mode)) ->	сокетом


**Разделим параметры на три вида:**

* Поведенчиские
    * R - рекурсивный поиск
* Филтры
    * a - скрытые файлы и дериктории
    * r - инвертировать сортировку
    * t - сортировать по времени
* Параметры оформления
    * l - вывеси ввиде таблици
    * G - добавить цвет
