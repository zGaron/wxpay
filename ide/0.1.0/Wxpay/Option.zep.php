<?php

namespace WXPay;

/**
 * WXPay\Option
 * 接口参数结构体
 */
class Option implements \ArrayAccess, \Countable
{

    /**
     * WXPay\Option constructor
     *
     * @param array $arrayParameter 
     */
    public function __construct($arrayParameter = null) {}

    /**
     * Allows to check whether an attribute is defined using the array-syntax
     * <code>
     * var_dump(isset($option['database']));
     * </code>
     *
     * @param mixed $index 
     * @return bool 
     */
    public function offsetExists($index) {}

    /**
     * Gets an attribute from the options, if the attribute isn't defined returns null
     * If the value is exactly null or is not defined the default value will be used instead
     * <code>
     * echo $option->get('controllersDir', '../app/controllers/');
     * </code>
     *
     * @param mixed $index 
     * @param mixed $defaultValue 
     */
    public function get($index, $defaultValue = null) {}

    /**
     * Gets an attribute using the array-syntax
     * <code>
     * print_r($option['database']);
     * </code>
     *
     * @param mixed $index 
     * @return string 
     */
    public function offsetGet($index) {}

    /**
     * Sets an attribute using the array-syntax
     * <code>
     * $option['database'] = array('type' => 'Sqlite');
     * </code>
     *
     * @param mixed $index 
     * @param mixed $value 
     */
    public function offsetSet($index, $value) {}

    /**
     * Unsets an attribute using the array-syntax
     * <code>
     * unset($option['database']);
     * </code>
     *
     * @param mixed $index 
     */
    public function offsetUnset($index) {}

    /**
     * Merges a options into the current one
     * <code>
     * $option = new \WXPay\Option(array('database' => array('host' => 'localhost')));
     * $globalOption->merge($option);
     * </code>
     *
     * @param mixed $option 
     * @return Option 
     */
    public function merge(Option $option) {}

    /**
     * Converts recursively the object to an array
     * <code>
     * print_r($option->toArray());
     * </code>
     *
     * @return array 
     */
    public function toArray() {}

    /**
     * Returns the count of properties set in the option
     * <code>
     * print count($option);
     * </code>
     * or
     * <code>
     * print $option->count();
     * </code>
     *
     * @return int 
     */
    public function count() {}

    /**
     * Restores the state of a WXPay\Option object
     *
     * @param array $data 
     * @return Option 
     */
    public static function __set_state($data) {}

    /**
     * Helper method for merge options (forwarding nested option instance)
     *
     * @param Option $option 
     * @param Option $instance = null
     * @return Option option
     */
    protected final function _merge(Option $option, $instance = null) {}

}
