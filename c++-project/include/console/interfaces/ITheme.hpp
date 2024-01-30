#ifndef ITHEME_HPP_
#define ITHEME_HPP_

class ITheme {
  public:
    virtual ~ITheme() = default;
    virtual const int getBackground() const = 0;
    virtual const int getText() const = 0;
    virtual const int getBorder() const = 0;
    virtual void setBackground(int color) = 0;
    virtual void setText(int color) = 0;
    virtual void setBorder(int color) = 0;
};

#endif /* !ITHEME_HPP_ */
