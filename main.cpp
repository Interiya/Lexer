#include <stdexcept>
#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>

int matrix[61][32] = {
        1,4,4,42,42,7,9,11,13,5,29,21,42,24,25,40,59,26,27,16,18,15,28,52,30,23,4,31,43,48,59,59,
        1,-1,-1,-1,-1,-1,-1,-1,-1,2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,49,-1,-1,
        3,-1,-1,-1,-1,-1,-1,-1,-1,45,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,49,-1,-1,
        4,4,4,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,4,-1,-1,4,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,6,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,8,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,10,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,36,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,12,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,14,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,20,-1,-1,-1,-1,17,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,19,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,22,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,38,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        32,32,32,32,47,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,56,32,32,32,32,
        34,34,34,34,47,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,33,34,34,46,34,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        34,34,34,34,47,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,35,34,34,46,34,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,60,-1,-1,-1,-1,
        36,36,36,36,-1,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,-1,-1,
        37,37,37,37,37,37,37,37,38,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,46,-1,
        37,37,37,37,37,37,37,37,38,37,37,37,37,37,37,37,37,37,39,37,37,37,37,37,37,37,37,37,37,37,46,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,42,41,41,41,41,41,41,41,41,41,41,41,41,41,46,-1,
        41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,42,41,41,41,41,41,41,41,41,41,41,41,41,41,46,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        44,44,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,44,-1,-1,
        44,44,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,44,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        4,4,4,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,4,-1,-1,4,-1,-1,
        50,-1,-1,-1,-1,51,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        53,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,54,-1,-1,-1,
        53,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        55,55,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,55,-1,-1,
        55,55,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,55,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,57,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,58,-1,-1,46,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        34,34,34,34,47,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,35,34,34,46,34,
};
using namespace std;

enum tokenType {NO_TOKEN=0, INTEGER, NO_FRACT, REAL, IDENT,
    KEYWORD, OP, SEP, CHAR, STRING, COMMENT, NO_HEX, HEX,
    N2, BAD_EOF, BAD_NL, NO_EXP, NO_CC, CHAR10, CHAR16, BAD_CHAR, ERROR, BAD_CC};
string tokenTypeName[] = {"","integer","NoFract","real","ident","keyword","op","sep","char",
                        "string","comment","NoHex","hex","n2", "BadEOF","BadNL","NoExp","NoCC",
                        "char#","char#$","BadChar","BadCC"};
enum symbolType { NUMBER=0, CHARACTER_A_F, CHARACTER_G_Z, TAB,
    NEXT_LINE, PLUS, MINUS, DIVISION, MULTIPLICATION, POINT,
    SEMICOLON, COLON, SPACE, LEFT_BRACKET, RIGHT_BRACKET,
    LEFT_BRACES, RIGHT_BRACES, LEFT_PARENTHESES,
    RIGHT_PARENTHESES, LEFT_CHEVRONS, RIGHT_CHEVRONS, CARET,
    AT_SIGN, HASH, COMMA, EQUALS, UNDERSCORE, PRIME, DOLLAR,
    CHARACTER_E, TILDE, OTHER_CHARACTER };
map<string, tokenType> token_type;
map<char, symbolType> symbol_type;
void initmap()
{
    symbol_type['\t'] = TAB;
    symbol_type['\n'] = NEXT_LINE;
    symbol_type['+'] = PLUS;
    symbol_type['-'] = MINUS;
    symbol_type['/'] = DIVISION;
    symbol_type['*'] = MULTIPLICATION;
    symbol_type['.'] = POINT;
    symbol_type[';'] = SEMICOLON;
    symbol_type[':'] = COLON;
    symbol_type[' '] = SPACE;
    symbol_type['['] = LEFT_BRACKET;
    symbol_type[']'] = RIGHT_BRACKET;
    symbol_type['{'] = LEFT_BRACES;
    symbol_type['}'] = RIGHT_BRACES;
    symbol_type['('] = LEFT_PARENTHESES;
    symbol_type[')'] = RIGHT_PARENTHESES;
    symbol_type['<'] = LEFT_CHEVRONS;
    symbol_type['>'] = RIGHT_CHEVRONS;
    symbol_type['^'] = CARET;
    symbol_type['@'] = AT_SIGN;
    symbol_type['#'] = HASH;
    symbol_type[','] = COMMA;
    symbol_type['='] = EQUALS;
    symbol_type['_'] = UNDERSCORE;
    symbol_type['\''] = PRIME;
    symbol_type['$'] = DOLLAR;
    symbol_type['~'] = TILDE;

    token_type["BadNL"] = ERROR;
    token_type["BadEOF"] = ERROR;
    token_type["BadChar"] = ERROR;
    token_type["NoExp"] = ERROR;
    token_type["NoFract"] = ERROR;
    token_type["NoHex"] = ERROR;
    token_type["NoCC"] = ERROR;
    token_type["BadC"] = ERROR;

    token_type["begin"] = KEYWORD;
    token_type["forward"] = KEYWORD;
    token_type["do"] = KEYWORD;
    token_type["else"] = KEYWORD;
    token_type["end"] = KEYWORD;
    token_type["for"] = KEYWORD;
    token_type["function"] = KEYWORD;
    token_type["if"] = KEYWORD;
    token_type["array"] = KEYWORD;
    token_type["of"] = KEYWORD;
    token_type["procedure"] = KEYWORD;
    token_type["program"] = KEYWORD;
    token_type["record"] = KEYWORD;
    token_type["then"] = KEYWORD;
    token_type["to"] = KEYWORD;
    token_type["type"] = KEYWORD;
    token_type["var"] = KEYWORD;
    token_type["while"] = KEYWORD;
    token_type["break"] = KEYWORD;
    token_type["continue"] = KEYWORD;
    token_type["downto"] = KEYWORD;
    token_type["exit"] = KEYWORD;
    token_type["repeat"] = KEYWORD;
    token_type["until"] = KEYWORD;

    token_type["and"] = OP;
    token_type["div"]= OP;
    token_type["mod"] = OP;
    token_type["not"] = OP;
    token_type["or"] = OP;
    token_type["xor"] = OP;
}

int symbolType(char s)
{
    if (s >= '0' && s <= '9')
        return NUMBER;
    if ((s == 'E') || (s == 'e'))
        return CHARACTER_E;
    if ((s >= 'A' && s <= 'F') || (s >= 'a' && s <= 'f'))
        return CHARACTER_A_F;
    if ((s >= 'G' && s <= 'Z') || (s >= 'g' && s <= 'z'))
        return CHARACTER_G_Z;
    else if (symbol_type[s] != 0)
        return symbol_type[s];
    else
        return OTHER_CHARACTER;
}

tokenType stateToTokenType[] = {NO_TOKEN,INTEGER,NO_FRACT,REAL ,IDENT ,OP,
                 SEP,OP,OP,OP,OP,OP,OP,OP,OP,OP,OP,OP,OP,OP,
                 OP,SEP,OP,OP,SEP,SEP,SEP,SEP,OP,SEP,SEP,
                 NO_TOKEN,NO_TOKEN,CHAR,NO_TOKEN,STRING,
                 COMMENT,NO_TOKEN,NO_TOKEN,COMMENT,NO_TOKEN,
                 NO_TOKEN,COMMENT,NO_HEX,HEX,N2,BAD_EOF,BAD_NL,
                 IDENT,NO_EXP,REAL,NO_EXP,NO_CC,CHAR10,NO_CC,CHAR16,
                 STRING,NO_TOKEN,CHAR,BAD_CHAR,NO_TOKEN};

char currentSymbol = '\0';
int q = 0;
int line = 1;
int column = 1;
ifstream fin("input.txt");
ofstream fout("output.txt");
int columnError = 0;

class LexerError
{
protected:
    int l;
    int c;
    tokenType msg;
public:
    LexerError (int L, int C, tokenType MSG)
    {
        l = L;
        c = C;
        msg = MSG;
    }
    void print (){
        cout << l << "\t" << c << "\t" << tokenTypeName[msg] << endl;
        fout << l << "\t" << c << "\t" << tokenTypeName[msg] << endl;
    }
    ~LexerError(){}
};
class Token
{
protected:
    int l;
    int c;
    tokenType type;
    string leks;
public:
    Token (int L, int C, tokenType TYPE, string LEKS)
    {
        l = L;
        c = C;
        type = TYPE;
        leks = LEKS;
    }
    virtual void print(){
        cout << l << "\t" << c << "\t" << tokenTypeName[type] << "\t" << leks << endl;
        fout << l << "\t" << c << "\t" << type << "\t" << leks << endl;
    }
    ~Token(){}
};
template<class V>
class TokenVal: public Token
{
    V val;
public:
    TokenVal(int L, int C, tokenType TYPE, string LEKS, V val):
            val(val),
            Token(L, C, TYPE, LEKS){}
    void print(){
        cout << l << "\t" << c << "\t" << type << "\t" << leks << "\t" << val << endl;
        fout << l << "\t" << c << "\t" << type << "\t" << leks << "\t" << val << endl;
    }
};
template<>
void TokenVal<double>::print() {
    char buf[11];
    sprintf(buf, "%.4E", val);
    buf[8] = buf[9]; buf[9] = buf[10]; buf[10] = 0;
    cout << l << "\t" << c << "\t" << type <<"\t" << leks << "\t" << buf << endl;
    fout << l << "\t" << c << "\t" << type <<"\t" << leks << "\t" << buf << endl;
}
void next_char()
{
    if (currentSymbol != '\0')
    {
        int currentSymbolType = symbolType(currentSymbol);
        if (currentSymbolType == NEXT_LINE) {
            line++;
            columnError = column;
            column = 1;
        } else if (currentSymbolType == TAB) {
            column = ((column - 1) / 4 + 1) * 4 + 1;
        }
        else column++;
    }
    fin >> currentSymbol;
    if (fin.eof()) currentSymbol = '~';
}
Token *bufer = NULL;

Token *get_token ()
{
    if (bufer != NULL)
    {
        Token *temp = bufer;
        bufer = NULL;
        return temp;
    }
    if (fin.eof()) return 0;
    string lexema = "";
    int lineCur = line;
    int columnCur = column;
    int currentState = 0;
    q = 0;
    while(true)
    {
        currentState = q;
        q = matrix[q][symbolType(currentSymbol)];
        if (q < 0) break;
        lexema += currentSymbol;
        next_char();
    }
    tokenType currentStateToTokenType = stateToTokenType[currentState];
    if (currentStateToTokenType == N2)
    {
        lexema = lexema.substr(0, lexema.size()-2);
        bufer = new Token(lineCur, column - 2, SEP, "..");
        currentStateToTokenType = INTEGER;
    }
    if ( currentStateToTokenType == INTEGER || currentStateToTokenType == HEX)
    {
        string s = lexema.substr(currentStateToTokenType == HEX ? 1 : 0, lexema.size());
        int a = strtol (s.c_str(), NULL, currentStateToTokenType == HEX ? 16 : 10);
        return new TokenVal<int>(lineCur, columnCur, currentStateToTokenType, lexema, a);
    }
    if (currentStateToTokenType == REAL)
    {
        double a = atof(lexema.c_str());
        return new TokenVal<double>(lineCur, columnCur, REAL, lexema, a);
    }
    if (currentStateToTokenType == IDENT && token_type[lexema] == KEYWORD)
        currentStateToTokenType = KEYWORD;
    if (currentStateToTokenType == IDENT && token_type[lexema] == OP)
        currentStateToTokenType = OP;
    if (currentStateToTokenType == CHAR)
    {
        char d = lexema[1];
        return new TokenVal<char>(lineCur, columnCur, currentStateToTokenType, lexema, d);
    }
    if (currentStateToTokenType == CHAR10 || currentStateToTokenType == CHAR16)
    {
        string s = lexema.substr(currentStateToTokenType == CHAR16 ? 2 : 1, lexema.size());
        int a = strtol (s.c_str(), NULL, currentStateToTokenType == CHAR16 ? 16 : 10);
        if (a > 127) throw new LexerError(lineCur,column,BAD_CC);
        currentStateToTokenType = CHAR;
        return new TokenVal<char>(lineCur, columnCur, currentStateToTokenType, lexema, (char)a);
    }
    if (currentStateToTokenType == STRING)
    {
        string s = lexema.substr(1,lexema.size()-2);
        int index = 0;
        while (true)
        {
            index = s.find("''",index);
            if (index == string::npos) break;
            s.replace (index, 2, "'");
            index ++;
        }
        return new TokenVal<string>(lineCur, columnCur, currentStateToTokenType, lexema, s);
    }
    if (token_type[tokenTypeName[currentStateToTokenType]] == ERROR)
    {
        if (currentStateToTokenType == BAD_NL)
            columnCur = columnError;
        else if (currentStateToTokenType == BAD_EOF)
        {
            lineCur = line;
            columnCur = column - 1;
        }
        else if (currentStateToTokenType == BAD_CHAR)
            columnCur = column - 1;
        else
            columnCur = column;
        throw new LexerError(lineCur,columnCur,currentStateToTokenType);
    }
    if (currentStateToTokenType == COMMENT)
    {
        return get_token();
    }
    return new Token(lineCur, columnCur, currentStateToTokenType, lexema);
}
int main()
{
    initmap();
    fin >> noskipws;
    next_char();
    Token *cur;
    try {
        while (cur = get_token()) {
            cur->print();
            delete cur;
        }
    }catch (LexerError *e) { e->print(); }
}
