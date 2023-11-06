#include <iostream>
#include <cpr/cpr.h>

using namespace std;


int main()
{
     // Создаем объект сессии
    cpr::Session session;
    
    // Устанавливаем URL для запроса
    session.SetUrl("http://httpbin.org/html");
    
    // Устанавливаем заголовок accept: text/html
    session.SetHeader(cpr::Header{{"accept", "text/html"}});
    
    // Выполняем запрос
    cpr::Response response = session.Get();
    
    // Проверяем успешность запроса
    if (response.status_code == 200) {
        // Ищем заголовок статьи между тегами <h1></h1>
        string html = response.text;
        size_t start_pos = html.find("<h1>");
        size_t end_pos = html.find("</h1>", start_pos);
        
        if (start_pos != string::npos && end_pos != string::npos) {
            string title = html.substr(start_pos + 4, end_pos - start_pos - 4);
            cout << "Заголовок статьи: " << title << std::endl;
        } else {
            cout << "Заголовок статьи не найден." << std::endl;
        }
    } else {
        cout << "Ошибка при выполнении запроса." << std::endl;
    }

    

    return 0;
}