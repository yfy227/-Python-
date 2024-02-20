def is_valid_id_card(id_card):
    # 验证身份证号码是否为18位
    if len(id_card) != 18:
        return "Error"  # 身份证号码不是18位，输出Error

    # 定义系数和对应的校验码字符
    coefficients = [7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2]
    validate_chars = ['1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2']

    try:
        # 计算加权和
        weighted_sum = sum(int(id_card[i]) * coefficients[i] for i in range(17))

        # 计算余数
        remainder = weighted_sum % 11

        # 比较校验码
        if id_card[17] == validate_chars[remainder]:
            return "校验正确"  # 校验码正确，输出Correct
        else:
            return "校验错误"  # 校验码错误，输出Wrong
    except ValueError:
        return "Error"  # 身份证号码中包含非数字字符，输出Error

# 如果是直接运行该脚本，则执行以下代码
if __name__ == "__main__":
    # 输入身份证号码
    id_card = input("请输入18位身份证号码：")

    # 调用函数进行验证
    result = is_valid_id_card(id_card)
    print(result)
