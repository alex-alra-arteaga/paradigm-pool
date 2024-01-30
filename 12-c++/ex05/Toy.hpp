/*
** EPITECH PROJECT, 2024
** Toy.hpp
** File description:
** Paradigm Seminar, ex05
*/

#ifndef TOY_HPP_
#define TOY_HPP_

#include "Picture.hpp"

class Toy {
public:
    enum ToyType {
        BASIC_TOY,
        ALIEN,
        BUZZ,
        WOODY
    };

    Toy() : _name("toy"), _type(BASIC_TOY), _picture(), _lastError() {};
    Toy(const ToyType type, const std::string &name, const std::string &file) : _name(name), _type(type), _picture(file), _lastError() {};
    Toy(const Toy &other);
    Toy(Toy &&other);

    ~Toy() = default;

    ToyType getType() const { return _type; };
    std::string getName() const { return _name; };
    Picture getPicture() const { return _picture; };
    std::string getAscii() const { return _picture.getData(); };
    void setName(const std::string &name) { _name = name; };
    bool setAscii(const std::string &file);
    virtual void speak(const std::string statement);
    virtual bool speak_es(const std::string statement);

    Toy &operator=(const Toy &other);
    Toy &operator<<(const std::string &str);

    class Error {
    public:
        enum ErrorType {
            UNKNOWN,
            PICTURE,
            SPEAK
        };

        Error() : type(UNKNOWN) {};
        Error(const ErrorType _type) : type(_type) {};
        ~Error() = default;

        std::string what() const {
            switch (type) {
                case UNKNOWN:
                    return "";
                case PICTURE:
                    return "bad new illustration";
                case SPEAK:
                    return "wrong mode";
                default:
                    return "";
            }
        };
        std::string where() const {
            switch (type) {
                case UNKNOWN:
                    return "";
                case PICTURE:
                    return "setAscii";
                case SPEAK:
                    return "speak_es";
                default:
                    return "";
            }
        };

        ErrorType type;
    };
    Error getLastError() const { return _lastError; };

private:
    std::string _name;
    ToyType _type;
    Picture _picture;
    Error _lastError;
};

std::ostream &operator<<(std::ostream &s, const Toy &toy);

#endif //TOY_HPP_