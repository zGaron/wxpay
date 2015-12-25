namespace WXPay\Library;

class Util {

	public static function make_sign (apiObject, string! key) -> string
	{
        array mergedArray = [];
        var v, signBody = "";
        let mergedArray = mergedArray->merge(apiObject->_required_properties, apiObject->_optional_properties);

        sort(mergedArray);
        for v in mergedArray {
            if ! empty apiObject->{v} {
                let signBody .= v . "=" . apiObject->{v} . "&";
            }
        }
        let signBody .= "key=" . key;
        if apiObject->debug {
            echo signBody . PHP_EOL;
        }
        return strtoupper(md5(signBody));
	}


    public static function genRandomString(int length = 24) -> string
    {
        string template = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        if length > 62 {
            let length = 62;
        }
        let template = str_shuffle(template);
        return substr(template, 0, length);
    }

    /**
     * 转换 xml 字符串为 数组格式.
     *
     * @param string $xml
     *
     * @return array
     */
    public static function convertXmlToArray(string xml) -> array
    {
        var xmlObj, resp_array, properties;
        var vk, dom;

        let xmlObj = simplexml_load_string(xml);
        let resp_array = [];
        let properties = get_object_vars(xmlObj);

        for vk, dom in properties {
            let resp_array[vk] = trim(dom);
        }

        return resp_array;
    }


    /**
     * 将数组转换为 xml 格式(字符串)
     *
     * @param array $arr
     *
     * @return string
     */
    public static function convertArrayToXml(array! arr) -> string
    {
        string xml = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<xml>\n";
        var k, v;
        for k, v in arr  {
            if !empty v && !is_array(v) {
                let xml .= "    <" . k . "><![CDATA[" . v . "]]></" . k . ">\n";
            }
        }
        let xml .= "</xml>";

        return xml;
    }




    /**
     * 获取客户端IP地址
     *
     * @return string
     */
    public static function getRealIp()
    {
        var ip;

        if getenv("HTTP_CLIENT_IP") && strcasecmp(getenv("HTTP_CLIENT_IP"), "unknown") {
            let ip = getenv("HTTP_CLIENT_IP");
        } elseif getenv("HTTP_X_FORWARDED_FOR") && strcasecmp(getenv("HTTP_X_FORWARDED_FOR"), "unknown") {
            let ip = getenv("HTTP_X_FORWARDED_FOR");
        } elseif getenv("REMOTE_ADDR") && strcasecmp(getenv("REMOTE_ADDR"), "unknown") {
            let ip = getenv("REMOTE_ADDR");
        } elseif  isset(_SERVER["REMOTE_ADDR"]) && _SERVER["REMOTE_ADDR"] && strcasecmp(_SERVER["REMOTE_ADDR"], "unknown") {
            let ip = _SERVER["REMOTE_ADDR"];
        } else {
            let ip = "unknown";
        }

        return ip;
    }



    /**
     * 使用商户的cert,key调用 wechat-api.
     *
     * @param $apiUri
     * @param $postXml
     * @param $cert
     * @param $key
     *
     * @return array
     * @throws SystemException
     */
    public static function callWeChatApi(string! apiUri, string! xml, string! cert = null, string! key = null, string! rootca = null)
    {
        var data, error_no, error_msg, ch;

        let ch = curl_init();
        curl_setopt(ch, CURLOPT_TIMEOUT, 30);
        curl_setopt(ch, CURLOPT_URL, apiUri);
        curl_setopt(ch, CURLOPT_SSL_VERIFYPEER, TRUE);
        curl_setopt(ch, CURLOPT_SSL_VERIFYHOST, 2);
        curl_setopt(ch, CURLOPT_HEADER, FALSE);
        curl_setopt(ch, CURLOPT_RETURNTRANSFER, TRUE);
        curl_setopt(ch, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V4);

        if ! empty cert {
            curl_setopt(ch, CURLOPT_SSLCERTTYPE, "PEM");
            curl_setopt(ch, CURLOPT_SSLCERT, cert);

            curl_setopt(ch, CURLOPT_SSLKEYTYPE, "PEM");
            curl_setopt(ch, CURLOPT_SSLKEY, key);

            curl_setopt(ch, CURLOPT_CAINFO, rootca);
        }

        curl_setopt(ch, CURLOPT_POST, TRUE);
        curl_setopt(ch, CURLOPT_POSTFIELDS, xml);

        let data = curl_exec(ch);

        //返回结果
        if !empty data {
            curl_close(ch);
            return Util::convertXmlToArray(data);
        } else {
            let error_no = curl_errno(ch);
            let error_msg = curl_error(ch);
            curl_close(ch);
            throw new \Exception("：Curl 出错 (".error_no.")!  " . error_msg);
        }
    }

}