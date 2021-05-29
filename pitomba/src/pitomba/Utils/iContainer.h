
#ifndef I_CONTAINER_H_
#define I_CONTAINER_H_


namespace pitomba {

    template <typename ObjId, typename Obj>
    class iContainer {
    public:

        virtual ~iContainer() = default;

        virtual Obj* add(const ObjId id) = 0;
        virtual Obj* get(const ObjId id) = 0;
        virtual void remove(const ObjId id) = 0;
        virtual void clear() = 0;
    };

}

#endif // I_CONTAINER_H_
