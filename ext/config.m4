PHP_ARG_ENABLE(wxpay, whether to enable wxpay, [ --enable-wxpay   Enable Wxpay])

if test "$PHP_WXPAY" = "yes"; then

	

	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, WXPAY_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_WXPAY, 1, [Whether you have Wxpay])
	wxpay_sources="wxpay.c kernel/main.c kernel/memory.c kernel/exception.c kernel/hash.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/extended/array.c kernel/string.c kernel/fcall.c kernel/extended/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/math.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/time.c kernel/exit.c wxpay/option.zep.c
	wxpay/api.zep.c
	wxpay/credential.zep.c
	wxpay/api/app/closeorder.zep.c
	wxpay/api/app/createorder.zep.c
	wxpay/api/app/createrefund.zep.c
	wxpay/api/app/queryorder.zep.c
	wxpay/api/app/queryrefund.zep.c
	wxpay/api/jsapi/closeorder.zep.c
	wxpay/api/jsapi/createorder.zep.c
	wxpay/api/jsapi/createrefund.zep.c
	wxpay/api/jsapi/queryorder.zep.c
	wxpay/api/jsapi/queryrefund.zep.c
	wxpay/api/micropay/autocodetoopenid.zep.c
	wxpay/api/micropay/closeorder.zep.c
	wxpay/api/micropay/createorder.zep.c
	wxpay/api/micropay/createrefund.zep.c
	wxpay/api/micropay/queryorder.zep.c
	wxpay/api/micropay/queryrefund.zep.c
	wxpay/api/micropay/shorturl.zep.c
	wxpay/api/native/closeorder.zep.c
	wxpay/api/native/createorder.zep.c
	wxpay/api/native/createrefund.zep.c
	wxpay/api/native/queryorder.zep.c
	wxpay/api/native/queryrefund.zep.c
	wxpay/api/native/shorturl.zep.c
	wxpay/api/transfer/createorder.zep.c
	wxpay/api/transfer/queryorder.zep.c
	wxpay/api/wap/createorder.zep.c
	wxpay/config.zep.c
	wxpay/credential/app.zep.c
	wxpay/credential/jsapi.zep.c
	wxpay/credential/native1.zep.c
	wxpay/library/util.zep.c "
	PHP_NEW_EXTENSION(wxpay, $wxpay_sources, $ext_shared,, )
	PHP_SUBST(WXPAY_SHARED_LIBADD)

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([wxpay], [pcre])
					AC_DEFINE([ZEPHIR_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([wxpay], [json])
					AC_DEFINE([ZEPHIR_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS

	PHP_INSTALL_HEADERS([ext/wxpay], [php_WXPAY.h])

fi
