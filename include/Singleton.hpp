#ifndef JOTTER_SINGLETON_HPP
#define JOTTER_SINGLETON_HPP

class Singleton
{
   public:
    Singleton(const Singleton&) = delete;

    Singleton& operator=(const Singleton&) = delete;

    Singleton(Singleton&&) = delete;

    Singleton& operator=(Singleton&&) = delete;

   protected:
    Singleton() = default;
};

#endif  // JOTTER_SINGLETON_HPP
