class DTFecha;

class IReloj{
    private:
        DTFecha* fecha;
    public:
        virtual void setFecha(DTFecha*);
        virtual DTFecha* getFecha();
};