#ifndef COMPLEJO_H
#define COMPLEJO_H


class Complejo
{
    public:
        Complejo(float r, float i);
        Complejo();
        virtual ~Complejo();

        const Complejo& sumar(const Complejo& otro);
        const Complejo& restar(const Complejo& otro);

        float modulo() const;

        void print() const;

    protected:
    private:
        float r;
        float i;
};

#endif // COMPLEJO_H
