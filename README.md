# wxpay

### Install

1. 使用 phpize 安装

``` bash
  git clone https://github.com/zGaron/wxpay.git
  cd wxpay/ext
  phpize
  ./configure --enable-wxpay
  make
  sudo make install
```

2. 使用 Zephir 编译安装

``` bash
  git clone https://github.com/zGaron/wxpay.git
  cd wxpay
  zephir build
```

### Usage

统一下单用法见文件
> `tests/app_test.php`

支付凭证的获取见文件
> `tests/app_credential_test.php`
