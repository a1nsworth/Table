#include "includes/task.h"

void outputFuncComp(keyAndValue kv) {
    while (*getKey_keyAndValue(kv).data != '\0') {
        printf("%c", *getKey_keyAndValue(kv).data);
        kv.key.data++;
    }

    printf("%s", " | ");

    printf("%d\n", getValue_keyAndValue(kv));
}

int main() {
    ProgrammingLanguage programmingLanguage = createEmpty_ProgrammingLanguage();
    writeToTable_ProgrammingLanguage(&(programmingLanguage.separators),
                                     "D:\\Programming\\C\\Table\\includes\\Separators.txt");
    writeToTable_ProgrammingLanguage(&(programmingLanguage.reservedWords),
                                     "D:\\Programming\\C\\Table\\includes\\ReservedWords.txt");

    table t = createEmpty_list();

    writeVariables_ProgrammingLanguage(programmingLanguage, &t, "D:\\Programming\\C\\Table\\includes\\Main.txt");

    output_list(t,outputFuncComp);

    return 0;
}
