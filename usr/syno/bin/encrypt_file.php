<?php
	function usage()
	{
		$str = <<<FILE
DESCRIPTION
	encrypted specified the file and output the encoded result

SYNOPSIS
	encrypt_file -a action -i input

OPTIONS
	--help,-h
		print this help text
	--action,-a
		[enc, dec]
	--input,-i
		input filename or hash value

EXAMPLES
    php encrypt_file.php -a enc -i encrypt_file.php
    php encrypt_file.php -a dec -i CVkBhm6fFuVUwoBCAAAAINEn+VUuP/Iq/f4afSTmp53tVU28yAso1uQPF+uXle6m

FILE;
		echo $str;
		exit(1);
	}

	function get_opts()
	{
		$shortopts = 'ha:i:';

		$longopts  = array(
			'help',
			'action',
			'input'
		);

		$opts = getopt($shortopts, $longopts);

		// merge options
		if (isset($opts['h'])) {
			$opts['help'] = $opts['h'];
		}
		if (isset($opts['a'])) {
			$opts['action'] = $opts['a'];
		}
		if (isset($opts['i'])) {
			$opts['input'] = $opts['i'];
		}

		if (isset($opts['help'])) {
			usage();
		}

		if (!isset($opts['action'], $opts['input'])) {
			usage();
		}

		return $opts;
	}

	function encrypt($input_file)
	{
		// get random header
		$rand_1 = mt_rand();
		$rand_2 = mt_rand();
		$rand_3 = mt_rand();

		$weight_key = ($rand_1 & 0x0000000f);
		$key        = ($rand_2 & 0xffffffff);

		$weight_iv  = ($rand_1 & 0x000000f0) >> 4;
		$iv         = ($rand_3 & 0xffffffff);

		// compute key
		$ekey = md5(sprintf("%u", $key));
		for ($i = 0 ; $i < $weight_key ; $i++) {
			$ekey = md5($ekey);
		}

		// compute iv
		$eiv = md5(sprintf("%u", $iv));
		for ($i = 0 ; $i < $weight_iv ; $i++) {
			$eiv = md5($eiv);
		}
		$encrypted = exec("openssl enc -aes-128-cbc -in $input_file -out $input_file.enc -K $ekey -iv $eiv");

		// pack
		$pack_1 = pack('N', $rand_1);
		$pack_2 = pack('N', $rand_2);
		$pack_3 = pack('N', $rand_3);
		$pack_4 = pack('N', strlen(file_get_contents("$input_file.enc")));

		// encode
		$encrypted = base64_encode($pack_1.$pack_2.$pack_3.$pack_4.file_get_contents("$input_file.enc"));
		unlink("$input_file.enc");

		return $encrypted;
	}

	function decrypt($data)
	{
		// decode
		$decoded = base64_decode($data);

		// unpack
		$unpack_1 = unpack('N', substr($decoded, 0, 4));
		$unpack_2 = unpack('N', substr($decoded, 4, 4));
		$unpack_3 = unpack('N', substr($decoded, 8, 4));
		$unpack_4 = unpack('N', substr($decoded, 12, 4));

		// get header
		$rand_1 = $unpack_1[1];
		$rand_2 = $unpack_2[1];
		$rand_3 = $unpack_3[1];
		$rand_4 = $unpack_4[1];

		$weight_key = ($rand_1 & 0x0000000f);
		$key        = ($rand_2 & 0xffffffff);

		$weight_iv  = ($rand_1 & 0x000000f0) >> 4;
		$iv         = ($rand_3 & 0xffffffff);

		// compute key
		$ekey = md5(sprintf("%u", $key));
		for ($i = 0 ; $i < $weight_key ; $i++) {
			$ekey = md5($ekey);
		}

		// compute iv
		$eiv = md5(sprintf("%u", $iv));
		for ($i = 0 ; $i < $weight_iv ; $i++) {
			$eiv = md5($eiv);
		}

		$enc = tempnam(getcwd(), 'enc-');
		$dec = tempnam(getcwd(), 'dec-');

		file_put_contents($enc, substr($decoded, 16));

		exec("openssl enc -d -aes-128-cbc -in $enc -out $dec -K $ekey -iv $eiv");

		$decrypted = file_get_contents($dec);
		unlink($enc);
		unlink($dec);

		return $decrypted;
	}

	$opts = get_opts();
	if ('enc' == $opts['action']) {
		echo encrypt($opts['input']);
	} else if ('dec' == $opts['action']){
		echo decrypt($opts['input']);
	} else {
		usage();
	}
?>
