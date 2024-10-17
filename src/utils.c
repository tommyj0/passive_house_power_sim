void normalise_arr(float *arr, int len, float factor) {
  float sum = 0;
  for (int i = 0; i < len; ++i) {
    sum += arr[i];
  }
  float mean = sum / len;
  for (int i = 0; i < len; ++i) {
    arr[i] = factor * arr[i] / mean;
  }
}

int find_month(int day) {
  switch (day) {
  case 0 ... 30:
    return 0; // January
  case 31 ... 59:
    return 1; // February
  case 60 ... 90:
    return 2; // March
  case 91 ... 120:
    return 3; // April
  case 121 ... 151:
    return 4; // May
  case 152 ... 181:
    return 5; // June
  case 182 ... 212:
    return 6; // July
  case 213 ... 243:
    return 7; // August
  case 244 ... 273:
    return 8; // September
  case 274 ... 304:
    return 9; // October
  case 305 ... 334:
    return 10; // November
  case 335 ... 365:
    return 11; // December
  default:
    return -1; // Invalid day
  }
}
