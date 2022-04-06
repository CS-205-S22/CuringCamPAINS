#ifndef CUSTOM_H
#define CUSTOM_H


class Custom
{
public:
    Custom();

    void levelUp();
    void addBackground();
    void addAvatar();
    void updateNotification();

private:
    int level = 0;
};

#endif // CUSTOM_H
