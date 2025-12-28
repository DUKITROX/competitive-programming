	auto start = chrono::high_resolution_clock::now();

	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed_seconds = end - start;
	#ifdef LOCAL
	cout << setprecision(3) << fixed << "Time: " << elapsed_seconds.count() << " seconds\n";
	#endif

