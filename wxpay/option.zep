namespace WXPay;

use WXPay\Option\Exception;
/**
 * WXPay\Option
 *
 * 接口参数结构体
 */
class Option implements \ArrayAccess, \Countable
{
	/**
	 * WXPay\Option constructor
	 */
	public function __construct(array! arrayParameter = null)
	{
		var key, value;

		for key, value in arrayParameter {
			this->offsetSet(key, value);
		}
	}

	/**
	 * Allows to check whether an attribute is defined using the array-syntax
	 *
	 *<code>
	 * var_dump(isset($option['database']));
	 *</code>
	 */
	public function offsetExists(var index) -> boolean
	{
		let index = strval(index);

		return isset this->{index};
	}

	/**
	 * Gets an attribute from the options, if the attribute isn't defined returns null
	 * If the value is exactly null or is not defined the default value will be used instead
	 *
	 *<code>
	 * echo $option->get('controllersDir', '../app/controllers/');
	 *</code>
	 */
	public function get(var index, var defaultValue = null)
	{
		let index = strval(index);

		if isset this->{index} {
			return this->{index};
		}

		return defaultValue;
	}

	/**
	 * Gets an attribute using the array-syntax
	 *
	 *<code>
	 * print_r($option['database']);
	 *</code>
	 */
	public function offsetGet(var index) -> string
	{
		let index = strval(index);

		return this->{index};
	}

	/**
	 * Sets an attribute using the array-syntax
	 *
	 *<code>
	 * $option['database'] = array('type' => 'Sqlite');
	 *</code>
	 */
	public function offsetSet(var index, var value)
	{
		let index = strval(index);

		if typeof value === "array" {
			let this->{index} = new self(value);
		} else {
			let this->{index} = value;
		}
	}

	/**
	 * Unsets an attribute using the array-syntax
	 *
	 *<code>
	 * unset($option['database']);
	 *</code>
	 */
	public function offsetUnset(var index)
	{
		let index = strval(index);

		//unset(this->{index});
		let this->{index} = null;
	}

	/**
	 * Merges a options into the current one
	 *
	 *<code>
	 * $option = new \WXPay\Option(array('database' => array('host' => 'localhost')));
	 * $globalOption->merge($option);
	 *</code>
	 */
	public function merge(<Option> option) -> <Option>
	{
		return this->_merge(option);
	}

	/**
	 * Converts recursively the object to an array
	 *
	 *<code>
	 *	print_r($option->toArray());
	 *</code>
	 */
	public function toArray() -> array
	{
		var key, value, arrayParameter;

		let arrayParameter = [];
		for key, value in get_object_vars(this) {
			if typeof value === "object" {
				if method_exists(value, "toArray") {
					let arrayParameter[key] = value->toArray();
				} else {
					let arrayParameter[key] = value;
				}
			} else {
				let arrayParameter[key] = value;
			}
		}
		return arrayParameter;
	}

	/**
	 * Returns the count of properties set in the option
	 *
	 *<code>
	 * print count($option);
	 *</code>
	 *
	 * or
	 *
	 *<code>
	 * print $option->count();
	 *</code>
	 */
	public function count() -> int
	{
		return count(get_object_vars(this));
	}

	/**
	 * Restores the state of a WXPay\Option object
	 */
	public static function __set_state(array! data) -> <Option>
	{
		return new self(data);
	}

	/**
	 * Helper method for merge options (forwarding nested option instance)
	 *
	 * @param Option option
	 * @param Option instance = null
	 *
	 * @return Option merged option
	 */
	protected final function _merge(<Option> option, var instance = null) -> <Option>
	{
		var key, value, number, localObject;

		if typeof instance !== "object" {
			let instance = this;
		}

		let number = instance->count();

		for key, value in get_object_vars(option) {

			if fetch localObject, instance->{key} {
				if typeof localObject === "object" && typeof value === "object" {
					if localObject instanceof Option && value instanceof Option {
						this->_merge(value, localObject);
						continue;
					}
				}
			}

			if typeof key == "integer" {
				let key = strval(number),
					number++;
			}
			let instance->{key} = value;
		}

		return instance;
	}
}
