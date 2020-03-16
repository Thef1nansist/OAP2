#include"Header.h"
void tanvarik2() {
    	int const N = 40;
    	int i = 1, word = 0, j = 0;
    	char str[N];
    	int arr[N];
    	ofstream fout("a.txt"); 
    	fout << " Работа с крабом онлайн"; // запись строки в файл (Поставьте пробел перед первым словом)
    	fout.close(); // закрываем файл
    	ifstream fin("a.txt"); // открыли файл для чтения
    	if (!fin.is_open()) // если файл не открыт
    		cout << "Файл не может быть открыт!\n"; // сообщить об этом
    	else
    	{	
    
    		while (fin.get(str[i])) {
    			cout << str[i];
    			if (str[i] == ' ') {
    				arr[j] = i; //запоминает порядок пробела
    				j++;
    			}
    			i++;
    		}
    
    		int m = 0, k = -1;
    		cout << endl;
    		for (i = 0; i < strlen(str); i++)
    		{
    			if ( str[i] == 'р' || str[i] == 'Р') {
    
    				for (m = arr[k]; m < arr[k + 1]; m++) //запись от пробела до следующего пробела
    				{
    					cout<< str[m]; //запись массива в c.txt
    				
    				}
    				
    			}
    			if (str[i] == ' ') {
    				k++;
    			}
    		
    		}
    
    		cout << endl;
    		system("pause");
    		fin.close();
    
    	}
}
void tanvarik1() {
    int const N = 100, number = 6;
    int i = 0, word = 0, j = 0;
    char str[N];
    char firstword[N];
    int arr[number];
    ifstream fin("b.txt"); // открыли файл для чтения
    if (!fin.is_open()) // если файл не открыт
        cout << "Файл не может быть открыт!\n"; // сообщить об этом
    else
    {
        while (fin.get(str[i])) {
            cout << str[i];
            if (str[i] == '\n') {
                arr[j] = i; //запоминает порядок пробела 
                j++;
            }
            i++;
        }
        ofstream fout("с.txt");
        int  num = 0;
        j = 0;
        cout << endl;
        for (i = 0; str[i] != '\n'; i++)
        {
            firstword[i] = str[i];
            firstword[i + 1] = '\0';
        }
        int length = strlen(firstword); //размер первого слова
        for (i = 0; i < length; i++)
        {
            fout << firstword[i]; //запись первого слова
        }
        int k = 0, m = 0;

        for (i = length + 1; i < strlen(str); i++, j++)
        {

            if (firstword[j] == str[i]) { //если элемент первого слова равен элементу массива то num++
                num++;
            }
            if (str[i] == '\n')
            {
                if (num < length) { //если num == length значит слова одинаковые и цикл снизу не сработает
                    for (m = arr[k]; m < arr[k + 1]; m++) //цикл от пробела до следующего пробела
                    {
                        fout << str[m]; //запись слов не одинаковых с первым
                    }
                }
                j = -1;
                k++;
                num = 0;
            }

        }

        cout << endl;
        system("pause");
        fin.close();

    }


}
void sixteenvarik2() {
    ofstream fout;
    fout.open("file_100.txt");

    char ch[512] = "string slkdfn xklfjb xkjbfa klf aldnfkh kjsdbvf zjhdv xvhjbasjd sjdhfvbgx";
    fout << ch;

    fout.close();

    ifstream fin;
    fin.open("file_100.txt");

    char** str = (char**)calloc(10, sizeof(char));
    for (int i = 0; i < 10; i++)
        str[i] = (char*)calloc(10, sizeof(char));

    int i = 0;
    while (!fin.eof()) {
        fin >> str[i];
        i++;
    }

    //for (int i = 0; i < 10; i++) {
    //    printf("%s\n", str[i]);
    //}

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++) {
            if (str[i][j] == 'x') {
                printf("%s\n", str[i]);
            }
        }
    fin.close();
    getchar();

}
void sixteenvarik1() {
    ifstream fin;
    fin.open("file_16.txt");
    ofstream fout;
    fout.open("file_26.txt");

    char*** Arr = new char** [10];
    for (int i = 0; i < 10; i++) {
        Arr[i] = new char* [30];
        for (int j = 0; j < 30; j++) {
            Arr[i][j] = new char[30];
        }
    }

    char ch;
    int str = 0, word = 0;
    while (!fin.eof()) {
        fin >> Arr[str][word];
        printf("Arr[%d][%d]: %s\n", str, word, Arr[str][word]);
        word++;
        fin.get(ch);
        if (ch == '\n') {
            str++;
            word = 0;
        }
    }


    bool norm = false;
    int Num = 0;
    int* num = (int*)calloc(10, sizeof(int));
    for (int i = 0; i < str; i++) {
        norm = false;
        for (int j = 0; j < 20; j++) {
            if (norm == true)
                break;
            for (int k = 0; k < 20; k++) {
                if (strcmp(Arr[i][j], Arr[i][k]) == 0 && j != k && k > j&& k < 11 && j < 11) {

                    for (int a = 0; a < 10; a++) {
                        fout << " ";
                        fout << Arr[i][a];
                    }
                    fout << '\n';
                    break;
                }
            }
        }
    }

    fout.close();
    fin.close();
    getchar();

}
void threevarik2() {
    setlocale(LC_ALL, "rus");
    char str[256];
    int k, j = 1, l = 1;
    ofstream file1("File1.txt");
    ifstream file2("File1.txt");
    ofstream file3("File2.txt");
    ifstream file4("File2.txt");
    file1 << "Жизнь очень хорошая\nкартина очень красивая\nпогода такая пасмурная\nптицы прилетают весной\nЛеший-мифическое чудовище\nолень\nлань\n";
    file1.close();
    cout << "Введите k от 1 до 7" << endl;
    cin >> k;
    while (!file2.eof())
    {
        file2.getline(str, 256);
        if (j >= k && j <= k + 3)
            file3 << str << "\n";
        j++;

    }
    file2.close();
    file3.close();
    while (!file4.eof())
    {
        file4.getline(str, 256);
        cout << str << endl;
        for (int i = 0; str[i] != 0; i++)
        {
            if (str[i] == 'a' || str[i] == 'е' || str[i] == 'у' || str[i] == 'ё' || str[i] == 'я' || str[i] == 'и' || str[i] == 'ю' || str[i] == 'о' || str[i] == 'э' || str[i] == 'ы')
                l++;
        }

    }
    cout << "Колчество гласных в строках равно=" << l << endl;
    file4.close();


}
void threevarik1() {
    char str[50];
    int k, i;
    ofstream file1("Filе3.txt");
    ifstream file2("File3.txt");
    ofstream file3("File4.txt");
    cout << "Вводим строку" << endl;
    cin.getline(str, 50);
    file1 << str;
    file1.close();
    while (!file2.eof())
    {
        file2.getline(str, 50);
        cout << "Строка прочитанная из файла:\t" << str << endl;
        cout << "Только cлова записаны в файл.\t";
        for (i = 0; i < strlen(str); i++)
        {
            if (str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9')

                file3 << str[i];
        }
    }
    file2.close();
    file3.close();
}
void sixvarik1() {
    ifstream fin;
    fin.open("file_11.txt");
    ofstream fout;
    fout.open("file_21.txt");
    char A[512];
    char B[40] = { 'b','B','c','C','d','D','f','F','g','G','h','H','j','J','K','k','l','L','m','M','n','N','P','p','q','Q','r','R','s','S','t','T','v','V','W','w','X','x','Z','z' };
    int count = 0;
    while (!fin.eof()) {
        if (fin.get() == '\n')
            count++;
    }

    fin.ios_base::clear();
    fin.seekg(0);


    int n = 2, k = 4, countL = 0;
    for (int i = 0; i < count; i++) {
        fin.getline(A, 512);
        if (i >= n - 1 && i <= k - 1) {
            for (int j = 0; j < sizeof(A); j++)
                for (int k = 0; k < sizeof(B); k++)
                    if (A[j] == B[k]) {
                        countL++;
                        cout << A[j] << endl;
                    }
            fout << A;
            fout << "\n";
        }
    }

    printf("\n\n\tgl: %d\n\n", countL);

    fout.close();
    fin.close();

}
void sixvarik2() {
    /* ofstream fout;
     fout.open("file_1.txt");

     char A[100];
     gets_s(A);
     fout << A;*/

    ifstream fin;
    fin.open("file_1.txt");

    char** Arr = new char* [60];
    for (int i = 0; i < 60; i++) {
        Arr[i] = new char[60];
    }


    int num = 0;
    while (!fin.eof()) {
        fin >> Arr[num];
        num++;
    }


    for (int i = 0; i < num; i++) {
        if (strlen(Arr[i]) % 2 == 0)
            cout << Arr[i] << endl;
    }

}
    int main(){
        setlocale(LC_CTYPE, "Rus");
        int k;
        while (1) {
            printf("Введите номер задания:");
            cin >> k;
            switch (k) {
            case 1:
                sixvarik1();
                break;
            case 2:
                sixvarik2();
                break;
            case 3:
                threevarik1();
                break;
            case 4:
                threevarik2();
                break;
            case 5:
                sixteenvarik1();
                break;
            case 6:
                sixteenvarik2();
                break;
            case 7:
                tanvarik1();
                break;
            case 8:
                tanvarik2();
                break;
            case 9:
                return 0;
            }

        }


    }
