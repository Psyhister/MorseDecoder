#ifndef RESULT_H
#define RESULT_H

#include <string>

enum class Status
{
    Ok,
    Error
};

template <typename T>
struct Result
{
    static Result<T> makeSuccess(const T& value)
    {
        Result res;
        res.status = Status::Ok;
        res.value = value;
        return res;
    };

    static Result<T> makeError(const std::string& errorMsg, Status status = Status::Error)
    {
        Result res;
        res.status = status;
        res.errorMsg = errorMsg;
        return res;
    };

    Status status;
    T value;

    std::string errorMsg;
};

#endif // RESULT_H
