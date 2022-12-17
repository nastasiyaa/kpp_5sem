package by.varvara.labs;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

@SpringBootApplication
@RestController
public class LabsApplication {

    public static void main(String[] args) {
        SpringApplication.run(LabsApplication.class, args); // Запуск приложения Spring
    }

    @GetMapping("/reverse") // Путь к методу
    public String reverse(@RequestParam(value = "value", required = false, defaultValue = "1234") String name) {
        return String.format("%s", reverseString(name)) + "<br><br><button onclick=\"history.back()\">Назад</button>"; // Возвращаем инвертированный текс с кнопкой назад
    }

    public static String reverseString(String input) { // Метод инвертирования
        char[] array = input.toCharArray(); // Создаем массив чаров
        String result = ""; // Результат
        for (int i = array.length - 1; i >= 0; i--) { // Обратный цикл для инвертирования
            result = result + array[i];
        }
        return result; // Возвращяем результат
    }

}
