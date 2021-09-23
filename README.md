# ACL_testTools
test project for Nokia

Описание проекта:
Проект разработан в среде Qt Creator 4.10.0. Версия Qt SDK 5.15.2.
Проект был изначально скомпилирован в ОС Windows непосредствнно средой разработки с помощью компилятора MinGW730_64. В ОС Linux исходники были собраны с помощью qmake и gсс make. Получен исполняемый файл.
В составе проекта отсутствуют какие-либо сторонние библиотеки. 
Проект не осуществляет подключение и/или создание каких-либо файлов.
Разработанное ПО носит исключительно демонстрационный характер.
В текущей ветке представлены исходники и приложен make-файл для сборки компилятором gcc под ОС Ubuntu.
Сборка и запуск осуществляется следующим образом:
1. Из консоли с помощью команды cd перейти в папку с исходниками;
2. Запустить команду make;
3. Запустить исполняемый файл.

Руководство по эксплуатации:

Разработанное ПО представляет из себя оконное приложение, осуществляющее два основных функционала:
1. Полноценный ACL;
2. Вход под учётной записью.

Вход под учётной записью осуществляется сразу после появления главного окна программы. Пара логин и пароль:
Логин: admin
Пароль: admin
В случае успешного совпадения пары, пользователь получает доступ к управлению базой ACL. В случае несовпадения пары пользователь получает предупреждение. Возможность повторного ввода логина и пароля сохраняется.
Функциональность ACL (в соотвествии с заданием) поддерживает:
1. Добавление нового пользователя;
2. Редактирование параметров доступа к любому процессу для любого пользователя (включая возможность удалить пользователя - пользователь в таком случае логируется в списке удалённых записей, повторная запись данного пользователя приведёт к обнулению прав доступа);
3. Просмотр прав доступа к любому процессу для любого пользователя.
На данный момент ПО не поддерживает запись пользователей с одинаковыми именами, однако в исходном коде заложена возможность корректировки алгоритма записи, которая позволит добавлять пользователей с одинаковыми именами.
Размеры базы данных фиксированный - 65535 записей. По необходимости, допустимо сделать размер базы динамическим.
Список зарегистированных процессов не редактируемый. Каждый новый пользователь получает один и тот же перечень процессов с правом доступа по умолчанию. Возможно сделать список процессов редактируемым.

