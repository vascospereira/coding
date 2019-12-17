#include <iostream>
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(*arr))

void remove_char(char *p, char c)
{
    if (p == NULL) return;

    char *pDest = p;
    while (*p)
    {
        if (*p != c) {
            *pDest++ = *p;
        }
        p++;
    }
    *pDest = '\0';
}

void remove_char_from_string()
{
    char str[] = "Vasco Manuel";
    char c = 'a';

    printf("before removing char '%c' in string: %s\n", c, str);
    remove_char(str, c);
    printf("after removing char '%c' -> %s\n", c, str);
}

int remove_duplicates(int *arr, int size)
{
    int prev = 0;
    for (int i = 1; i < size; i++)
    {
        if (arr[i] != arr[prev]) {
            arr[++prev] = arr[i];
        }
    }

    return prev + 1;
}

void remove_duplicates_from_sorted_array()
{
    int arr[] = { 1, 1, 2, 3, 3, 4, 5, 5, 6 };
    std::cout << "array with duplicates: { 1, 1, 2, 3, 3, 4, 5, 5, 6 }" << std::endl;

    int size = ARRAY_SIZE(arr);
    int count = remove_duplicates(arr, size);
    for (int i = 0; i < count; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}

void reverse(char *p)
{
    if (p == NULL) return;

    char *start = p;
    char *end = start + strlen(p) - 1;

    while (start < end)
    {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

void reverse_string()
{
    char str[] = "abcd";
    printf("original: '%s'\n", str);
    reverse(str);
    printf("reversed: '%s'\n", str);
}

void binary(int n)
{
    if (n == 0) return;
    
    binary(n / 2);
    std::cout << n % 2;
}

void number_binary_format()
{
    int num = 6;
    std::cout << "binary format of " << num << " -> ";
    binary(num);
    std::cout << std::endl;
}

int count_words(char *p)
{
    if (p == NULL) return NULL;

    int counter = 0;
    int len = 0;

    while (*p)
    {
        if (*p == ' ') { 
            len = 0; 
        }
        else if (++len == 1) { 
            counter++; 
        }

        p++;
    }

    return counter;
}

void count_string_words()
{
    char str[] = "we count the number of words in the string";
    
    int n = count_words(str);
    printf("number of words in '%s': %d\n", str, n);
}

void remove_duplicates_str(std::string &s)
{
    if (s.empty()) return;

    int count[256] = { 0 };
    int current = 0, next = 0;
    while (s[current])
    {
        if (++count[s[current]] == 1) {
            s[next++] = s[current];
        }
        ++current;
    }

    s[next] = '\0';
}

void remove_duplicates_from_string()
{
    std::string str = "aaabcdff";
    printf("original: '%s'\n", str.c_str());
    remove_duplicates_str(str);
    printf("removed duplicates: '%s'\n", str.c_str());
}

void remove_chars(char* p, const char* chars)
{
    if (p == NULL || chars == NULL) return;

    int bucket_counter[256] = { 0 };
    while (*chars)
    {
        bucket_counter[*chars++] = 1;
    }

    char* p_dest = p;

    while (*p)
    {
        if (bucket_counter[*p] != 1) {
            *p_dest++ = *p;
        }
        p++;
    }
    *p_dest = '\0';
}

void remove_multi_char_from_string()
{
    char str[] = "not so many words";
    char to_remove[] = "so";
    printf("remove chars '%s' from string '%s'\n",to_remove, str);
    remove_chars(str, to_remove);
    printf("after removed: '%s'\n", str);
}

int reverse(int number)
{
    int right_digit = 0;
    int rev = 0;
    while (number != 0)
    {
        right_digit = number % 10;
        number = number / 10;
        rev = rev * 10 + right_digit;
    }
    return rev;
}

void reverse_number()
{
    int num = 1234;
    std::cout << "number to reverse: " << num << std::endl;
    int reversed = reverse(num);
    std::cout << "reversed: " << reversed << std::endl;
}

int cab(int num)
{
    int counter = 0;
    while (num > 0)
    {
        if (num & 1) {
            counter++;
        }
        num >>= 1;
    }
    return counter;
}

void count_active_bits()
{
    int res = cab(9);
    printf("active bits: %d\n", res);
}

bool is_pal(const char *p)
{
    if (p == NULL) return false;
    const char *start = p;
    const char *end = start + strlen(p) - 1;

    while (start < end)
    {
        if (*start++ != *end--) {
            return false;
        }
    }
    return true;
}

void is_palindrome()
{
    const char *word[] = { "racecar", "bob", "test", "ohoh" };
    for (size_t i = 0; i < ARRAY_SIZE(word); i++)
    {
        printf("%s => %s\n", word[i], is_pal(word[i]) ? "PAL" : "NOT PAL");
    }
}

unsigned int s_length(char *p)
{
    unsigned int counter = 0;
    while (*p++)
    {
        counter++;
    }
    return counter;
}

void string_len()
{
    char str[] = "bier";
    std::cout << "string: " << str << std::endl;
    int sl = s_length(str);
    std::cout << "string length: " << sl << std::endl;
}

void fnrc(char *p)
{
    if (p == NULL) return;
    int aux[256] = { 0 };
    char *c = p;
    while (*p)
    {
        if (++aux[*p] == 1) {
            *c++ = *p;
        }
        p++;
    }
    *c = '\0';
}

void first_non_repeated_chars()
{
    char sentence[] = "this is a great sentence";
    printf("repeated chars: '%s'\n", sentence);
    fnrc(sentence);
    printf("first non repeated chars: '%s'\n", sentence);
}

bool ia(const char *first, const char *second)
{
    if (first == NULL || second == NULL) return false;
    
    int aux[256] = { 0 };
    while (*first)
    {
        aux[*first]++;
        first++;
    }

    while (*second)
    {
        aux[*second]--;
        if (aux[*second] < 0) return false;
        second++;
    }

    return true;
}

void is_anagram()
{
    const char* word[] = { "add", "ada", "listen", "silent", "late", "tale", "on", "no" };
    for (size_t i = 0; i < ARRAY_SIZE(word); i += 2)
    {
        printf("%s vs %s -> %s\n", word[i], word[i + 1], ia(word[i], word[i + 1]) ? "ANAGRAM" : "NOT ANAGRAM");
    }
}

const char *locis(const char *p, const char c)
{
    if (p == NULL) return NULL;
    
    const char *aux = NULL;
    while (*p)
    {
        if (*p == c) {
            aux = p;
        }
        p++;
    }

    return aux;
}

void last_occurrence_char_in_string()
{
    const char str[] = "this is a great string";
    const char c = 'i';

    printf("'%s'\n", str);
    const char *index = locis(str, c);
    printf("last occurrence char in string of '%c' index -> %d\n", c, index - str + 1);
}

char mrcis(std::string &s)
{
    if (s.empty()) return 0;

    int aux[256] = { 0 };
    int current = 0, max = 0;
    char c = 0;
    
    while (s[current])
    {
        if (++aux[s[current]] > max) {
            max = aux[s[current]];
            c = s[current];
        }
        current++;
    }
    
    return c;
}

void most_repeated_char_in_string()
{
    std::string str = "this string is big";
    std::cout << "'" << str << "'" << std::endl;
    const char c = mrcis(str);
    printf("most repeated char -> '%c'\n", c);
}

bool valid_number(const char *p)
{
    if (p == NULL) return false;
    
    int dot = 0, minus = 0, plus = 0;

    while (*p)
    {
        char c = *p;
        switch (c)
        {
        case'.':
            if (++dot > 1) return false;
            break;
        case'-':
            if (++minus > 1) return false;
            break;
        case'+':
            if (++plus > 1) return false;
            break;
        default:
            if (c < '0' || c > '9') return false;
            break;
        }
        p++;
    }

    return true;
}

void check_string_as_valid_number()
{
    const char *nums[] = { "123", ".34", "hello", "-45", "9", "--3", "23.2.1", "45.8", "+12", "0" };
    for (size_t i = 0; i < ARRAY_SIZE(nums); i++)
    {
        printf("%s -> %s\n", nums[i], valid_number(nums[i]) ? "valid number" : "not valid number");
    }
}

bool is_unique(const char *p)
{
    if (p == NULL) return false;
    
    int aux[256] = { 0 };

    while (*p)
    {
        if (++aux[*p] > 1) {
            return false;
        }
        p++;
    }

    return true;
}

void unique_char_in_string()
{
    const char str[] = "this is a unique string!";
    printf("'%s' -> %s\n", str, is_unique(str) ? "yes" : "no");
}

std::string common_letters(char *f, char *s)
{
    if (f == NULL || s == NULL) return "";

    int aux[256] = { 0 };

    while (*f)
    {
        ++aux[*f];
        f++;
    }

    std::string r;
    while (*s)
    {
        if (aux[*s] > 0) {
            r.push_back(*s);
            aux[*s] = 0;
        }
        s++;
    }
    return r;
}

void find_common_letter()
{
    char first[] = "abcdt";
    char second[] = "tcdwd";
    std::cout << "words: '" << first << "' <-> '" << second << "'" << std::endl;
    std::string result = common_letters(first, second);
    std::cout << "common letters: " << result << std::endl;
}

int main()
{
    // remove a char from a string
    remove_char_from_string();
    // remove duplicates from a sorted array
    remove_duplicates_from_sorted_array();
    // reverse a string
    reverse_string();
    // print a number in binary
    number_binary_format();
    // count number of words in a string
    count_string_words();
    // remove duplicates from a string
    remove_duplicates_from_string();
    // remove multiple char from a string
    remove_multi_char_from_string();
    // reverse a number
    reverse_number();
    // active bit counter
    count_active_bits();
    // check if is palindrome
    is_palindrome();
    // strlen implementation
    string_len();
    // first nonrepeated chars in a sentence
    first_non_repeated_chars();
    // anagrams
    is_anagram();
    // last occurrence of a char in a string
    last_occurrence_char_in_string();
    // most repeated char in a string
    most_repeated_char_in_string();
    // check if a string is a valid number
    check_string_as_valid_number();
    // determine if all chars are unique in a string
    unique_char_in_string();
    // find common letter between two strings
    find_common_letter();
}