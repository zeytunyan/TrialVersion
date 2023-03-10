# TrialVersion

Программа на С++, написанная для лабораторной работы по Информационной безопасности. Цель работы - создание trial-версии программы, защищенной от взлома. Чтобы программу было сложнее взломать, написан очень непонятный, запутанный и громоздкий код.   

## Назначение программного продукта

Программный продукт меняет дату и время изменения выбранного файла в соответствии с требованиями пользователя.

## Описание способа скрытия информации о числе запусков программы
* Для сокрытия информации о числе запусков программы используются три различных файла, пути к которым зашифрованы.
* Эти файлы располагаются по адресам:
  * C:\ProgramData\info.txt
  * C:\ProgramData\C\winlog.txt
  * C:\ProgramData\D\winLog.txt
* Один из них служит для отвлечения внимания, хотя информация в него записывается также, как и в другие два.
* Данные о количестве запусков хранятся в этих файлах в зашифрованном виде, причём для шифрования используется не тот алгоритм, который используется для шифрования путей к файлам.
* Дата и время их открытия и изменения остаются прежними после того, как программа перезаписывает зашифрованное значение в этих файлах. 
* При запуске программы они создаются, если все втроем отсутствуют на диске (это сделано для удобства, чтобы самостоятельно не пересоздавать эти файлы во время тестирования, очевидно, что такое поведение программы является возможностью для её взлома). При этом если присутствует хотя бы один из трёх этих файлов, а какие-то другие удалены, то новые вместо них не создаются, а программа перестает работать. 

## Методы защиты от взлома
1. Информация о количестве запусков программы не хранится в одном
месте. Контрольные данные хранятся в двух файлах, которые
расположены в разных местах.
2. Файлы с информацией о количестве запусков хранятся не в каталоге с
программой.
3. Информация о количестве запусков хранится в файлах в
зашифрованном виде.
4. Используются оригинальные алгоритмы шифрования.
5. Установка программы не требует прав администратора. Файлы с
контрольными данными расположены в папках, доступных всем
пользователям (не в корневом каталоге).
6. Путь к файлам зашифрован с помощью оригинального алгоритма
шифрования.
7. Число запусков не анализируется сразу после его получения.
8. Для проверки контрольных данных не используется функция или
библиотека.
9. Сразу после проверки числа запусков не выполняются действия,
связанные с результатом проверки.
10. Результаты проверок не хранятся в переменных.
11. Используются отвлекающий файл, хранящий число запусков.
12. Используется отвлекающая функция проверки.
13. Путь к файлам и количество запусков шифруются разными
алгоритмами.
14. Контрольные данные не хранятся в реестре.
15. Названия переменных и функций не отражают их назначения, часто
являются абстрактными, либо вовсе представляют из себя ничего не
значащий набор букв.
16. Используется сложная для понимания структура кода.

## Описание алгоритмов шифрования

### Алгоритм для шифрования путей к файлам:
1. На вход алгоритму подаётся строка, которую необходимо зашифровать.
2. Вычисляется длина этой строки.
3. Используется строка – ключ (“dfc”). Создаётся новая строка, которая представляет из себя повторяющуюся много раз строку-ключ. Новая строка имеет такую же длину, как и поданная на вход (например, “dfcdfcdfcdfcdfc”).
4. К каждому символу поданной на вход строки и соответствующему символу сформированной строки применяется операция побитового исключающего или (^).
5. Результат операции преобразуется в тип int и суммируется с числом 20.
6. Получившееся целочисленное значение добавляется в массив типа int.
7. Получившийся в результате массив целых чисел – результат шифрования.

### Алгоритм для шифрования количества запусков:
1. В алгоритме используются две строки: первая содержит буквы алфавита, цифры и некоторые другие символы, которые отсортированы в правильном порядке. Во второй строке все эти символы стоят в случайном порядке, вперемешку.
2. На вход подаётся строка, которую необходимо зашифровать.
3. Для каждого символа поданной на вход строки находится его позиция в строке с отсортированными символами.
4. Затем из строки с перемешанными символами берётся символ, стоящий на найденной позиции.
5. Этот символ преобразуется в целое число и добавляется в массив типа int.
6. Получившийся в результате массив целых чисел – результат шифрования.
