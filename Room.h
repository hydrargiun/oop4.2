#ifndef OOP4_LENA_ROOM_H
#define OOP4_LENA_ROOM_H
#include <string>
namespace oop4 {
    /*!
	\brief Абстрактный базовый класс
	\author hydragiun
	\version 1.0
	\date декабрь 2020 года
	\warning не возможно создать объект данного класса, не используя наследниеов

	Содержит чисто виртуальные функции
*/
    class Room {
    private:
        int num;  ///< номер комнаты, важен так же и для контейнера, число больше нуля.
        int busy; ///<  флаг busy принимает значения либо 0 либо один
        int people; ///<  колличество людей в комнате
        int cost_per_day; ///<  стоимость комнаты за день
        std::string type; ///<  тип номера (Lux, Standart Multiseat)


    public:
         friend std::ostream& operator << (std::ostream& out, const Room&);
         Room &Set_first(int n, int c, const std::string&); ///  \details выставляет пременные при первом создании \arg n - номер \arg c - уена \arg str - тип
         Room &Set_busy(int); /// \details выставляет значение флага busy \arg p флаг busy
         Room &Set_people(int); /// \details   выставляет значение колличества людей \arg amount - колличесвто человек
         int Get_busy() const; /// \details Возвращает флаг busy
         int Get_number() const ; /// \details Возвращает номер комнаты
         int Get_people() const; /// \details Возвращает колличество людей в номере
         int Get_cost() const; /// \details Возвращает стоимость за один день проживания
         std::string Get_type(); /// \details Возвращает тип номера
         virtual Room& Take(int d, int t, int p) = 0; /// \details чисто виртуальная функция реализованная  в классах наследниках, Функция занятия номера, принимает в качестве аргументов дату начала проживания, время и колличество человек  \arg d - дата начала \arg t - время проживания \arg p - id или колличество человек
         virtual Room& Checkout(int p) = 0; /// \details   чисто виртуальная функция реализованная  в классах наследниках, Функция освобождения номера, принимает в качестве аргумента для номеров класса Lux и Standart колличество челоек для выселения, а для Multiseat это поле используется для выселение человека по его id номеру
         virtual int Cost(int p) = 0;  /// \details   чисто виртуальная функция реализованная  в классах наследниках, Возвращает полную стоимость проживания в номере, лгика аргументов как и в Checkout \arg p - d или колличество человек
        virtual std::ostream& show(std::ostream&)const = 0; /// \details вывод полной информации о номере

         

    };
}

#endif